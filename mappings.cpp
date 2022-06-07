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
    void printRange(std::string_view message, const auto& range)
    {
        std::cout << "printRange  " << message;
        for (const auto& value : range) { std::cout << value; }
        std::cout << std::endl;
    }

    void print(const auto&& r) {
        std::cout << "\nRange:  ";
        for (auto i : r)
            std::cout << i << "  ";
        std::cout << std::endl;
    }

    void printText(std::string_view message, const auto& text)
    {
        std::cout << std::endl << message;
        std::cout << std::endl << text << std::endl;
    }

    auto basic::toString()
    {
        auto s =
          std::views::iota(10)
          | std::ranges::views::take(15)
          | std::ranges::views::transform([](int x) -> std::string {
              return std::to_string(x) + "|"; }) ;

              return s;
    }

  void basic::test()
  {
      std::cout << std::endl  << "Start mappings test" << std::endl;
      printRange("toString result:  " ,toString() );
  }

}

