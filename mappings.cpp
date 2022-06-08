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

    void printRange(std::string_view message, const auto& r)
    {
        std::cout << std::endl << message << std::endl;
        for (const auto& value : r) 
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

    auto basic::toString()
    {
        return 
            std::views::iota(1)
            | std::ranges::views::take(123)
            | std::ranges::views::transform([](int x) -> std::string {
            return std::to_string(x) + " "; });
    }

    auto basic::squareRootPair()
    {
        return
            std::views::iota(10)
            | std::ranges::views::take(25)
            | std::ranges::views::transform([](int x) -> std::pair<int, float> {
                return std::make_pair(x, sqrt(x));
                });
    }

    auto basic::squareRoot(const auto& r)
    {
        return
            r
            | std::ranges::views::take(25)
            | std::ranges::views::transform([](int x) -> std::pair<int, float> {
                return std::make_pair(x, sqrt(x));
                });
    }

  void basic::test()
  {
      std::cout << std::endl  << "Start mappings test" << std::endl;
      printRange("toString result:  " ,toString() );
      printPairs("squareRootPair result:  " , squareRootPair() );
      printPairs("squareRoot result:  " , squareRoot(std::views::iota(100)) );
  }

}

