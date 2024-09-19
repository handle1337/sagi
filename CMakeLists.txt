include(CMakePrintHelpers)
include(CheckCXXCompilerFlag)

cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
project(sagi VERSION 0.1.0 LANGUAGES C CXX)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /sdl /guard:cf /utf-8 /diagnostics:caret /w14165 /w44242 /w44254 /w44263 /w34265 /w34287 /w44296 /w44365 /w44388 /w44464 /w14545 /w14546 /w14547 /w14549 /w14555 /w34619 /w34640 /w24826 /w14905 /w14906 /w14928 /w45038 /W4 /permissive- /volatile:iso /Zc:inline /Zc:preprocessor /Zc:enumTypes /Zc:lambda /Zc:__cplusplus /Zc:externConstexpr /Zc:throwingNew /EHsc")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /machine:x64 /gua")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

#set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
#set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
#set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
#set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME     ON)  # link Boost Static libraries

#FIND_PACKAGE(Boost)
#IF (Boost_FOUND)
#    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
#    ADD_DEFINITIONS( "-DHAS_BOOST" )
#ENDIF()

add_executable(sagi 
"src/main.cpp"
"src/lox.cpp"
"src/scanner.cpp"
"src/tokens.cpp"
)
target_include_directories(sagi PRIVATE include)

include(CTest)
enable_testing()