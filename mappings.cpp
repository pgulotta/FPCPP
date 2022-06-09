module;

module mappings;

import <ranges>;
import <iostream>;
import <algorithm>;
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

    auto basic::toString()
    {
        return 
            std::views::iota(1)
            | std::ranges::views::take(123)
            | std::ranges::views::transform([](int x) -> std::string {
            return std::to_string(x) + " "; });
    }

    auto basic::squareRoot(const auto& r, int count)
    {
        std::cout << std::endl << "Count = " << count;
        return
            r
            | std::ranges::views::take(count)
            | std::ranges::views::transform([](int x) -> std::pair<int, float> {
                return std::make_pair(x, sqrt(x));
                });
    }

  void basic::test()
  {
      std::cout << std::endl  << "Start mappings test" << std::endl;
      printRange("toString result:  " ,toString() );
      printPairs("squareRoot result:  ", squareRoot(std::views::iota(10), 0));
      printPairs("squareRoot result:  ", squareRoot(std::views::iota(100), 22));

      const int values[]{1,3,5,222,444,100,144,7,6,4,2,111 };
      printPairs("squareRoot result:  ", squareRoot(values, sizeof(values) / sizeof(values[0])) );
      printPairs("squareRoot result:  ", squareRoot(values, 300));
      printPairs("squareRoot result:  ", squareRoot(values, 0));
  }

}

