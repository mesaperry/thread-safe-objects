include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(Test test_mutex.cpp)
target_link_libraries(Test gtest_main)

include(GoogleTest)
gtest_discover_tests(Test)