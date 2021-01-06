cmake_minimum_required(VERSION 3.14)
project(MatrixMatrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(MatrixMatrix STATIC
        Matrix.cpp Matrix.h
        RowIterator.cpp RowIterator.h
        ConstRowIterator.cpp ConstRowIterator.h
        ColumnIterator.cpp ColumnIterator.h
        ConstColumnIterator.cpp ConstColumnIterator.h
        )
target_include_directories(MatrixMatrix PUBLIC .)
target_link_libraries(MatrixMatrix PUBLIC MatrixVector)
target_compile_options(MatrixMatrix PRIVATE -Wall -Wextra -Werror)
