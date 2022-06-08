export module mappings;

import <span>;
import <string>;
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

export namespace mappings
{

  namespace basic
  {
      auto toString();
      auto squaredPair();
      


      void test();

  }
}