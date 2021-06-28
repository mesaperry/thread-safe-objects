CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (TSO)
set (CMAKE_CXX_STANDARD 11)

include_directories (include)
add_subdirectory (test)
enable_testing ()
add_test (NAME MyTest COMMAND Test)