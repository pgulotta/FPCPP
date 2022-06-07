module;

module mappings;

import <iostream>;
#include <cassert>

void print(auto&& r) {
    std::cout << "\nRange:  ";
    for (auto i : r)
        std::cout << i << "  ";
    std::cout << std::endl;
}

namespace mappings
{
  void averages::test()
  {
      test_int();
      std::cout << std::endl;
      test_float();
  }

  void averages::test_int()
  {
      const int values[]{ 1,8, 14, 5, 10, 8, 1,1 };
      print(values);

      const int values2[]{ 1,8, 14, 3, 4, 8, 21, 3 };
      print(values2);
  }

  void averages::test_float()
  {
      const double values[]{ 10.3, 8.3, 4.5, 5.6, 10.3, 8.3, 10.3,10.3 };
      print(values);

      const double values2[]{ 2.345 };
      print(values2);

  }
}

