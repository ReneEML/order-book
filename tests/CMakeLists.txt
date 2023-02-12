include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include(CTest)

add_executable(
        TestLimit
        TestLimit.cpp)
target_link_libraries(
        TestLimit
        GTest::gtest_main
        order_book
)
include(GoogleTest)
add_test(LIMIT_TEST AllTestsInB COMMAND TestLimit)