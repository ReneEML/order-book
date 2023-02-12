include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include(CTest)

add_executable(
        Tests
        TestLimit.cpp TestBook.cpp)
target_link_libraries(
        Tests
        GTest::gtest_main
        order_book
)
include(GoogleTest)
