cmake_minimum_required(VERSION 2.8.9)
project (DateUnitTest)

#CMAKE_SOURCE_DIR-.
# Gtest linking and working

enable_testing()
find_package(GTest REQUIRED)
#find_library(MyLib NAMES name libUrs.a)
#include_directories()

# Path to the ur core library to be tested....
set(URLIB /home/hacker/work/GE-Learn/ThreadSync/UnitTestWork/libUrs.a )

add_executable(DateUnitTest DateUnitTest.cpp )
#link_directories(UrLib.a)
#add_executable(DateUnitTestexe UrLib.a  DateUnitTest ) 
#target_link_libraries(DateUnitTest gtest gtest_main /home/hacker/work/GE-Learn/ThreadSync/UnitTestWork/libUrs.a )
target_link_libraries(DateUnitTest gtest gtest_main ${URLIB} )

#target_link_libraries(DateUnitTest gtest gtest_main ${MyLib} )

add_test(AllTestsInDateUnitTest DateUnitTest)
