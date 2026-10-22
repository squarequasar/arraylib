#include "arraylib.h"

#include <iomanip>
#include <iostream>

int main() {
    const int data[] = {5, 3, 8, 1, 9, 2};
    const std::size_t n = sizeof(data) / sizeof(data[0]);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Data:";
    for (std::size_t i = 0; i < n; ++i) std::cout << ' ' << data[i];
    std::cout << "\nSum: " << arr_sum(data, n)
              << "\nMax: " << arr_max(data, n)
              << "\nMin: " << arr_min(data, n)
              << "\nAverage: " << arr_average(data, n)
              << "\nPositive: " << arr_count_positive(data, n)
              << "\nNegative: " << arr_count_negative(data, n)
              << "\nZero: " << arr_count_zero(data, n)
              << "\nProduct: " << arr_product(data, n) << '\n';
}
