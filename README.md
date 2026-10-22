# Arraylib

C++17 array operations library. Laboratory work 2, variant 25.

The interface uses a pointer to const int and a std::size_t length.
Preconditions: the pointer addresses at least n elements and n > 0.
The mathematical sum and product must fit in int. Inputs are not modified.
arr_median sorts a copy and returns double, without changing the input array.

## Build and test

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
./build/app
./build/app_static
```

Windows with a multi-configuration generator: build with --config Release,
test with -C Release and run build/Release/app.exe.

Static output: libarraylib.a on macOS/Linux, arraylib.lib on MSVC.
Shared output: libarraylib.dylib on macOS, libarraylib.so on Linux,
arraylib.dll on Windows. CMake configures the runtime search path on Unix;
the DLL is generated beside the executables on Windows.

The stages directory contains the single-file and modular source versions.
