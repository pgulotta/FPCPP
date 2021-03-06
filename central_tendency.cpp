module;

module central_tendency;

import <iostream>;
#include <cassert>

namespace central_tendency
{
    void print(auto&& r) {
        std::cout << "\nRange:  ";
        for (auto i : r)
            std::cout << i << "  ";
        std::cout << std::endl;
    }

  bool compare_float(double x, double y, double epsilon = 0.01) {
        return (fabs(x - y) < epsilon);
  }

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

      auto amean{ central_tendency::averages::arithmeticMean<int>(values) };
      std::cout << "Arithmetic mean: " << amean.value() << std::endl;
      assert(amean.value() == 6.0);

      auto gmean{ central_tendency::averages::geometricMean<int>(values) };
      std::cout << "Geometric mean: " << gmean.value() << std::endl;
      assert(compare_float(gmean.value(),3.81426));

      auto root_mean_square{ central_tendency::averages::rms<int>(values) };
      std::cout << "Root mean square: " << root_mean_square.value() << std::endl;
      assert(compare_float(root_mean_square.value(), 7.51664));

      auto median{ central_tendency::averages::median<int>(values) };
      std::cout << "Median: " << median.value() << std::endl;
      assert(compare_float(median.value(), 6.5));

      auto mode{ central_tendency::averages::mode<int>(values) };
      std::cout << "Mode: " << mode.value() << std::endl;
      assert(mode == 1);

      const int values2[]{ 1,8, 14, 3, 4, 8, 21, 3 };
      print(values2);

      auto amean2{ central_tendency::averages::arithmeticMean<int>(values2) };
      assert(amean2.value() == 7.75);
      std::cout << "Arithmetic mean: " << amean2.value() << std::endl;

      auto gmean2{ central_tendency::averages::geometricMean<int>(values2) };
      assert(compare_float(gmean2.value(), 5.35616));
      std::cout << "Geometric mean: " << gmean2.value() << std::endl;

      auto root_mean_square2{ central_tendency::averages::rms<int>(values2) };
      std::cout << "Root mean square: " << root_mean_square2.value() << std::endl;
      assert(compare_float(root_mean_square2.value(), 10.));

      auto median2{ central_tendency::averages::median<int>(values2) };
      std::cout << "Median: " << median2.value() << std::endl;
      assert(compare_float(median2.value(), 6.));

      auto mode2{ central_tendency::averages::mode<int>(values2) };
      assert(!mode2.has_value());
      std::cout << "Mode is not unique" << std::endl;
  }

  void averages::test_float()
  {
      const double values[]{ 10.3, 8.3, 4.5, 5.6, 10.3, 8.3, 10.3,10.3 };
      print(values);

      auto amean{ central_tendency::averages::arithmeticMean<double>(values) };
      std::cout << "Arithmetic mean: " << amean.value() << std::endl;
      assert(compare_float(amean.value(), 8.4875));

      auto gmean{ central_tendency::averages::geometricMean<double>(values) };
      std::cout << "Geometric mean: " << gmean.value() << std::endl;
      assert(compare_float(gmean.value(), 8.15386));

      auto root_mean_square{central_tendency::averages::rms<double>(values)};
      std::cout << "Root mean square: " << root_mean_square.value() << std::endl;
      assert(compare_float(root_mean_square.value(), 8.75892));
 
      auto median{central_tendency::averages::median<double>(values)};
      std::cout << "Median: " << median.value() << std::endl;
      assert(compare_float(median.value(), 9.30000));

      auto mode{central_tendency::averages::mode<double>(values)};
      std::cout << "Mode: " << mode.value() << std::endl;
      assert(compare_float(mode.value(), 10.30000));

      const double values2[]{ 2.345 };
      print(values2);
      auto amean2{ central_tendency::averages::arithmeticMean<double>(values2) };
      std::cout << "Arithmetic mean: " << amean2.value() << std::endl;
      auto gmean2{ central_tendency::averages::geometricMean<double>(values2) };
      std::cout << "Geometric mean: " << gmean2.value() << std::endl;
      auto root_mean_square2{ central_tendency::averages::rms<double>(values2) };
      std::cout << "Root mean square: " << root_mean_square2.value() << std::endl;
      auto median2{ central_tendency::averages::median<double>(values2) };
      std::cout << "Median: " << median2.value() << std::endl;
      auto mode2{ central_tendency::averages::mode<double>(values2) };
      std::cout << "Mode: " << mode2.value () << std::endl;
      assert(compare_float(mode2.value(), 2.345));
   
  }
}

