cmake_minimum_required(VERSION 3.6)
project(DumbExpressionCompiler)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp
        src/Lexer/DexLexer.cpp src/Lexer/DexLexer.hpp
        src/Lexer/DexTokenType.hpp src/Lexer/DexTokenType.cpp
        src/Lexer/DexToken.cpp src/Lexer/DexToken.hpp
        src/Parser/DexASTExpr.cpp src/Parser/DexASTExpr.hpp
        src/Parser/DexASTExprType.cpp src/Parser/DexASTExprType.hpp
        src/Parser/DexParser.cpp src/Parser/DexParser.hpp
        src/AsmWriter/DexAsmWriter.cpp src/AsmWriter/DexAsmWriter.hpp
        src/CodeGenerator/DexCodeGenerator.cpp src/CodeGenerator/DexCodeGenerator.hpp)

add_executable(DumbExpressionCompiler ${SOURCE_FILES})

add_custom_target(DumbExpressionCompilerMakefile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMAND make)