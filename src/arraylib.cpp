#include "arraylib.h"

#include <algorithm>
#include <vector>

double arr_median(const int* arr, std::size_t n) {
    std::vector<int> sorted(arr, arr + n);
    std::sort(sorted.begin(), sorted.end());
    if (n % 2 != 0) return sorted[n / 2];
    return (static_cast<double>(sorted[n / 2 - 1])
            + static_cast<double>(sorted[n / 2])) / 2.0;
}

int arr_sum(const int* arr, std::size_t n) {
    long long result = 0;
    for (std::size_t i = 0; i < n; ++i) result += arr[i];
    return static_cast<int>(result);
}

int arr_max(const int* arr, std::size_t n) {
    int result = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] > result) result = arr[i];
    }
    return result;
}

int arr_min(const int* arr, std::size_t n) {
    int result = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] < result) result = arr[i];
    }
    return result;
}

double arr_average(const int* arr, std::size_t n) {
    long double result = 0;
    for (std::size_t i = 0; i < n; ++i) result += arr[i];
    return static_cast<double>(result / n);
}

int arr_count_positive(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] > 0) ++result;
    }
    return result;
}

int arr_count_negative(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] < 0) ++result;
    }
    return result;
}

int arr_count_zero(const int* arr, std::size_t n) {
    int result = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == 0) ++result;
    }
    return result;
}

int arr_product(const int* arr, std::size_t n) {
    // A zero makes the result zero even if an earlier partial product is large.
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == 0) return 0;
    }
    long long result = 1;
    for (std::size_t i = 0; i < n; ++i) result *= arr[i];
    return static_cast<int>(result);
}
