mkdir build

g++-10 --std=c++20 -g -c main.cpp -o build/main.o
g++-10 --std=c++20 -g -c Src1.cpp -o build/Src1.o
g++-10 build/main.o build/Src1.o -o build/mainSrc
g++-10 build/Src1.o build/main.o -o build/srcMain
