cmake_minimum_required(VERSION 3.21)
project(Applied_Cryptography)

set(CMAKE_CXX_STANDARD 14)

add_executable(Applied_Cryptography main.cpp)
add_executable(Mono "Monoalphabetic LAB 2.cpp")
add_executable(playFair playfair.cpp)
add_executable(DES DES.cpp)
add_executable(RSA RSA.cpp)
