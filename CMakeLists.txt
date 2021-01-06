cmake_minimum_required(VERSION 3.14)
project(MatrixVector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(MatrixVector STATIC
        BaseVector.cpp BaseVector.h
        Vector.cpp Vector.h
        VectorIterator.cpp VectorIterator.h
        ConstVectorIterator.cpp ConstVectorIterator.h
        VectorRef.cpp VectorRef.h
        ConstBaseVector.cpp ConstBaseVector.h
        ConstVectorRef.cpp ConstVectorRef.h)
target_include_directories(MatrixVector PUBLIC .)
target_link_libraries(MatrixVector PUBLIC MatrixMatrix)
target_compile_options(MatrixVector PRIVATE -Wall -Wextra -Werror)
