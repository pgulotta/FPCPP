module;

module mappings;

import <ranges>;
import <iostream>;
import <string>;
import <format>;
import <string_view>;
#include <cassert>



namespace mappings
{
    void printPairs(std::string_view message, const auto& pairs)
    {
        std::cout << std::endl  << message << std::endl;
        for (const auto& pair : pairs) {
            std::cout << pair.first << "  " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }

    void printRange(std::string_view message, const auto& range)
    {
        std::cout << std::endl << message << std::endl;
        for (const auto& value : range) 
        { 
            std::cout << value; 
        }
        std::cout << std::endl;
    }

    void printText(std::string_view message, const auto& text)
    {
        std::cout << std::endl << message;
        std::cout << std::endl << text << std::endl;
    }

    //void print(const auto&& r) {
    //    std::cout << std::endl;
    //    for (auto i : r)
    //        std::cout << i << "  ";
    //    std::cout << std::endl;
    //}

    auto basic::toString()
    {
        return 
            std::views::iota(1)
            | std::ranges::views::take(123)
            | std::ranges::views::transform([](int x) -> std::string {
            return std::to_string(x) + " "; });
    }

    auto basic::squaredPair()
    {
        return
            std::views::iota(10)
            | std::ranges::views::take(25)
            | std::ranges::views::transform([](int x) -> std::pair<int, float> {
                return std::make_pair(x, sqrt(x));
                });
    }


  void basic::test()
  {
      std::cout << std::endl  << "Start mappings test" << std::endl;
      printRange("toString result:  " ,toString() );
      printPairs("squaredPair result:  " , squaredPair() );
  }

}

