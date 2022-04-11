mkdir build
cd build
cmake ..
cmake --build .
cpack -G ZIP -C DEBUG