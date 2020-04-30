cmake_minimum_required(VERSION 3.15)
project(Test0X2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test0X2 main.cpp Graf.cpp Graf.h GrafMatrix.cpp GrafMatrix.h GrafList.cpp GrafList.h DijkstraAlgorithm.cpp DijkstraAlgorithm.h BellmanFord.cpp BellmanFord.h Path.h MyVec.h)