module;

module central_tendency;

import <iostream>;
#include <cassert>

bool compare_float(double x, double y, double epsilon = 0.01) {
    return (fabs(x - y) < epsilon);
}

void print(auto&& r) {
    for (auto i : r)
        std::cout << i << "  ";
    std::cout << std::endl;
}

namespace central_tendency
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

      double amean{ central_tendency::averages::arithmeticMean<int>(values) };
      std::cout << "Arithmetic mean: " << amean << std::endl;
      assert(amean == 6.0);

      double gmean{ central_tendency::averages::geometricMean<int>(values) };
      std::cout << "Geometric mean: " << gmean << std::endl;
      assert(compare_float(gmean,3.81426));

      double root_mean_square{ central_tendency::averages::rms<int>(values) };
      std::cout << "Root mean square: " << root_mean_square << std::endl;
      assert(compare_float(root_mean_square, 7.51664));

      auto median{ central_tendency::averages::median<int>(values) };
      std::cout << "Median: " << median << std::endl;
      assert(compare_float(median, 6.5));

      auto mode{ central_tendency::averages::mode<int>(values) };
      std::cout << "Mode: " << mode << std::endl;
      assert(mode == 1);

      const int values2[]{ 1,8, 14, 3, 4, 8, 21, 3 };
      std::cout << "************************" << std::endl;
      print(values2);
      auto mode2{ central_tendency::averages::mode<int>(values2) };
      assert(mode2 == std::numeric_limits<int>::quiet_NaN());
      std::cout << "Mode is not unique" << std::endl;
  }

  void averages::test_float()
  {
      const double values[]{ 10.3, 8.3, 4.5, 5.6, 10.3, 8.3, 10.3,10.3 };
      print(values);

      auto amean{ central_tendency::averages::arithmeticMean<double>(values) };
      std::cout << "Arithmetic mean: " << amean << std::endl;
      assert(compare_float(amean, 8.4875));

      auto gmean{ central_tendency::averages::geometricMean<double>(values) };
      std::cout << "Geometric mean: " << gmean << std::endl;
      assert(compare_float(gmean, 8.15386));

      auto root_mean_square{central_tendency::averages::rms<double>(values)};
      std::cout << "Root mean square: " << root_mean_square << std::endl;
      assert(compare_float(root_mean_square, 8.75892));
 
      auto median{central_tendency::averages::median<double>(values)};
      std::cout << "Median: " << median << std::endl;
      assert(compare_float(median, 9.30000));

      auto mode{central_tendency::averages::mode<double>(values)};
      std::cout << "Mode: " << mode << std::endl;
      assert(compare_float(mode, 10.30000));

      const double values2[]{ 2.345 };
      std::cout << "************************" << std::endl;
      print(values2);
      auto mode2{ central_tendency::averages::mode<double>(values2) };
      std::cout << "Mode: " << mode2 << std::endl;
      assert(compare_float(mode2, 2.345));

  }
}

