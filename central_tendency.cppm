export module central_tendency;

import <span>;
import <map>;
import <vector>;
import <iostream>;
import <limits>;   // For std::numeric_limits<double>::quiet_NaN()
import <ranges>;
import <string_view>;
import <algorithm>;
import <functional>;
import <utility>;

#include <cmath>  // For std::pow(), std::sqrt(), ...

namespace ranges = std::ranges;
namespace views =  std::ranges::views;

export namespace central_tendency
{
  auto square(const auto& x) { return x*x; }

  namespace averages
  {
      template <typename T> double rms(std::span<const T> data) requires std::floating_point<T> || std::integral<T>
    {
        // The RMS or root mean square is defined as square root of the arithmetic mean of the squares of the elements.
        T sum_squares{};
        for (auto value : data)
            sum_squares += square(value);

        return data.empty()
            ? std::numeric_limits<double>::quiet_NaN() 
            : std::sqrt(sum_squares / (double)data.size());
    }

    template <typename T> double geometricMean(std::span<const T> data) requires std::floating_point<T> || std::integral<T>
    {
        // The geometric mean of n elements is defined as the n-th root of the product of all n elements
        T product{ 1 };
        for (auto value : data)
            product *= value;

        return data.empty()
            ? std::numeric_limits<int>::quiet_NaN()
            : std::pow(product, 1.0 / (double)data.size());
    }

    template <typename T> double arithmeticMean(std::span<const T> data) requires std::floating_point<T> || std::integral<T>
    {
        // The arithmetic mean, the most commonly used average, is defined as the sum of all elements divided by the number of elements.
        T sum{};
        for (auto value : data)
            sum += value;

        return data.empty()
            ? std::numeric_limits<int>::quiet_NaN() 
            : sum / (double)data.size();
    }

    template <typename T> double median(std::span<const T> data) requires std::floating_point<T> || std::integral<T>
    {
        // The median of an odd number of elements is the value in the middle position of these elements when they are sorted.
        // The median of an even number of elements is typically defined as the mean of the two middle elements in a sorted range.
        std::vector<T> sorted;
        ranges::copy(data, back_inserter(sorted));
        ranges::sort(sorted);

        const size_t mid = data.size() / 2;
        return data.empty() ? std::numeric_limits<int>::quiet_NaN()
            : data.size() % 2 == 1 ? sorted[mid]
            : (sorted[mid - 1] + sorted[mid]) / 2.0;
    }

    template <typename T> T mode_old(std::span<const T> data) requires std::floating_point<T> || std::integral<T>
    {
        if (data.empty())
            return std::numeric_limits<T>::quiet_NaN();

        using Items = std::vector<T>;
        Items sorted;
        ranges::copy(data, back_inserter(sorted));

        ranges::sort(sorted);
        auto [first, last] {ranges::unique(sorted)};
        sorted.erase(first, last);

        std::multimap<size_t, T> countedData;
        for (auto item : sorted)
        {
            const auto counted{ ranges::count_if(data, [&item](auto i) {return item == i; }) };
            countedData.emplace(std::make_pair(counted, item));
        }
      
        if (countedData.size() != 1)
        {
            if ((countedData.crbegin())->first == (++countedData.crbegin())->first)
                return std::numeric_limits<T>::quiet_NaN();
        }
        return (countedData.crbegin())->second;
    }

    template <typename T> T mode(std::span<const T> data) requires std::floating_point<T> || std::integral<T>
    {
        if (data.empty())
            return std::numeric_limits<T>::quiet_NaN();

        using Items = std::vector<T>;
        Items dataCopy;
        ranges::copy(data, back_inserter(dataCopy));

        ranges::sort(dataCopy);
        auto [first, last] {ranges::unique(dataCopy)};
        dataCopy.erase(first, last);

        std::multimap<size_t, T> countedData;
        for (auto item : dataCopy)
        {
            const auto counted{ ranges::count_if(data, [&item](auto i) {return item == i; }) };
            countedData.emplace(std::make_pair(counted, item));
        }

        if (countedData.size() != 1)
        {
            if ((countedData.crbegin())->first == (++countedData.crbegin())->first)
                return std::numeric_limits<T>::quiet_NaN();
        }
        return (countedData.crbegin())->second;
    }


    void test();
    void test_int();
    void test_float();
  }
}