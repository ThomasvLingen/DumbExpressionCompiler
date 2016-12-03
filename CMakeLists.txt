cmake_minimum_required(VERSION 3.6)
project(DumbExpressionCompiler)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp
        src/Lexer/DexLexer.cpp src/Lexer/DexLexer.hpp
        src/Lexer/DexTokenType.hpp
        src/Lexer/DexToken.cpp src/Lexer/DexToken.hpp)

add_executable(DumbExpressionCompiler ${SOURCE_FILES})