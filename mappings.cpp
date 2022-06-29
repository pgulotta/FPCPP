module;

module mappings;

import <ranges>;
import <iostream>;
import <algorithm>;
import <string>;
import <format>;
import <iterator>;
import <string_view>;
import <vector>;
import <functional>;
import <utility>;



#include <cassert>

namespace ranges = std::ranges;
namespace views = std::ranges::views;

namespace mappings
{
    void printMap(std::string_view message, const std::multimap<int, int>& pairs)
    {
        std::cout << std::endl  << message << std::endl;
        std::cout << std::endl  << "Map items count:  "  << pairs.size() << std::endl;
        for (const auto& pair : pairs ) {
            std::cout << pair.first << "  " << pair.second << std::endl;
        }
        std::cout<< "End printMap" << std::endl;
    }

   void printPairs(std::string_view message, const auto& pairs)
    {
        std::cout << std::endl << message << std::endl;
        for (const auto& pair : pairs) {
            std::cout << pair.first << "  " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }

    void printRange(std::string_view message, const auto& items)
    {
        std::cout << std::endl << message << std::endl;
        for (const auto& value : items) 
        { 
            std::cout << value; 
        }
        std::cout << std::endl;
    }

    auto basic::toString()
    {
        return 
            std::views::iota(1)
            | std::ranges::views::take(123)
            | std::ranges::views::transform([](int x) -> std::string {
            return std::to_string(x) + " "; });
    }

    auto basic::squareRoot(const auto& rng, int count)
    {
        std::cout << std::endl << "Count = " << count;
        return
            rng
            | std::ranges::views::take(count)
            | std::ranges::views::transform([](int x) -> std::pair<int, float> {
            return std::make_pair(x, sqrt(x));
                });

    }

    std::multimap <int, int> basic::occurencesCount(const std::vector<int>& rng)
    {
        std::multimap<int, int> counted;
        
        // typename std::remove_const<decltype(rng)>::type  dataCopy;
        std::vector<int> dataCopy;
        ranges::copy(rng, std::back_inserter(dataCopy));
        ranges::sort(dataCopy);
        auto [first, last] {ranges::unique(dataCopy)};
        dataCopy.erase(first, last);
        auto counts =
            dataCopy | views::transform([&rng](int x) -> std::pair<int, int> {
            return std::make_pair(
                ranges::count_if(rng, [&x](auto i) {return x == i; }),  x);
                }) 
            
            ;

        for (const auto& pair : counts) {
            counted.emplace(pair.first, pair.second);
        }

        return counted;
    }

    void basic::test()
    {
        std::cout << std::endl << "Start mappings test" << std::endl;
        printPairs("occurencesCount:  ", occurencesCount(std::vector<int> { 21, 3, 1,8, 14, 3, 4, 8, 21, 3,9 }));
        printPairs("occurencesCount:  ", occurencesCount(std::vector<int>{1,2,3,4,5}));


    }

}

