#include "arraylib.h"

#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>

static bool close(double a, double b) {
    return std::fabs(a - b) < 1e-9;
}

int main() {
    const int a[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(a) / sizeof(a[0]);
    assert(arr_sum(a, n) == 7);
    assert(arr_max(a, n) == 8);
    assert(arr_min(a, n) == -5);
    assert(close(arr_average(a, n), 7.0 / 6.0));
    assert(arr_count_positive(a, n) == 3);
    assert(arr_count_negative(a, n) == 2);
    assert(arr_count_zero(a, n) == 1);
    assert(arr_product(a, n) == 0);

    const int one[] = {-7};
    assert(arr_sum(one, 1) == -7);
    assert(arr_min(one, 1) == -7);
    assert(arr_max(one, 1) == -7);
    assert(close(arr_average(one, 1), -7));
    assert(arr_product(one, 1) == -7);
    assert(arr_count_positive(one, 1) == 0);
    assert(arr_count_negative(one, 1) == 1);
    assert(arr_count_zero(one, 1) == 0);

    const int zeros[] = {0, 0, 0};
    assert(arr_sum(zeros, 3) == 0);
    assert(arr_product(zeros, 3) == 0);
    assert(arr_count_zero(zeros, 3) == 3);
    const int product[] = {-2, 3, -4};
    assert(arr_product(product, 3) == 24);
    const int extremes[] = {INT_MAX, INT_MIN};
    assert(arr_sum(extremes, 2) == -1);
    assert(close(arr_average(extremes, 2), -0.5));
    const int large_zero[] = {INT_MAX, INT_MAX, INT_MAX, 0};
    assert(arr_product(large_zero, 4) == 0);
    const int large_average[] = {INT_MAX, INT_MAX};
    assert(close(arr_average(large_average, 2), INT_MAX));
    std::cout << "[unit] All tests passed\n";
}
