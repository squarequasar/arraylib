#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    const int concentration[] = {124, 131, 118, 145, 139, 127, 152, 133};
    const std::size_t n = sizeof(concentration) / sizeof(concentration[0]);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Concentration samples:";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << ' ' << concentration[i] / 100.0;
    }

    int above_threshold = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (concentration[i] > 130) ++above_threshold;
    }

    std::cout << "\nSample count: " << n
              << "\nMinimum: " << arr_min(concentration, n) / 100.0
              << "\nMaximum: " << arr_max(concentration, n) / 100.0
              << "\nAverage: " << arr_average(concentration, n) / 100.0
              << "\nMedian: " << arr_median(concentration, n) / 100.0
              << "\nSamples above 1.30: " << above_threshold << '\n';
}
