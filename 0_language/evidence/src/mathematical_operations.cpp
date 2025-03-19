#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <numeric>
#include "utilities.hpp"

template<std::floating_point FloatingPointType>
constexpr bool are_equal(
    FloatingPointType a,
    FloatingPointType b,
    FloatingPointType epsilon = std::numeric_limits<FloatingPointType>::epsilon()
) {
    return abs(a - b) < epsilon;
}

int main()
{
    static_assert(are_equal(std::tgamma(0.5f), std::sqrt(static_cast<float>(M_PI)), 1e-6f));
    static_assert(are_equal(std::tgamma(0.5), std::sqrt(static_cast<double>(M_PI)), 1e-15));

    exit_program(EXIT_SUCCESS);
}
