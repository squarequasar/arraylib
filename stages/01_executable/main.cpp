#ifndef ARRAYLIB_H
#define ARRAYLIB_H

#include <cstddef>

#if defined(_WIN32) && !defined(ARRAYLIB_STATIC)
#if defined(ARRAYLIB_BUILD)
#define ARRAYLIB_API __declspec(dllexport)
#else
#define ARRAYLIB_API __declspec(dllimport)
#endif
#else
#define ARRAYLIB_API
#endif

ARRAYLIB_API int arr_sum(const int* arr, std::size_t n);
ARRAYLIB_API int arr_max(const int* arr, std::size_t n);
ARRAYLIB_API int arr_min(const int* arr, std::size_t n);
ARRAYLIB_API double arr_average(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_positive(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_negative(const int* arr, std::size_t n);
ARRAYLIB_API int arr_count_zero(const int* arr, std::size_t n);
ARRAYLIB_API int arr_product(const int* arr, std::size_t n);

#endif


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
