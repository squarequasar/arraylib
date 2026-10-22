#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

int main() {
    const int data[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    const std::size_t n = sizeof(data) / sizeof(data[0]);
    assert(arr_sum(data, n) == 45);
    assert(arr_max(data, n) == 9);
    assert(arr_min(data, n) == 1);
    const double average = arr_average(data, n);
    assert(average >= arr_min(data, n));
    assert(average <= arr_max(data, n));
    assert(std::fabs(average * n - arr_sum(data, n)) < 1e-9);

    const int mixed[] = {-4, 0, 2, -1, 0, 6};
    assert(arr_count_positive(mixed, 6) + arr_count_negative(mixed, 6)
               + arr_count_zero(mixed, 6) == 6);
    assert(arr_product(mixed, 6) == 0);
    std::cout << "[integration] All tests passed\n";
}
