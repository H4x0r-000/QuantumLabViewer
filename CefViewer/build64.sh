mkdir -p build
cd build

cmake -G "Visual Studio 16 2019" -T v140_xp ../
cmake --build . --target libcef_dll_wrapper --config debug
cmake --build . --target libcef_dll_wrapper --config release

cd ..