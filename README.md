# CppFreeMock

CppFreeMock is a header only library for mocking functions in C++.
The project is based from [gzc9047](https://github.com/gzc9047/CppFreeMock#), merging the win32 platform support from
[zadockmaloba](https://github.com/zadockmaloba/CppFreeMock).

The project is restructed for better import to an exsting project.

# Requirements

- gtest and gmock (make sure can be static linked with command -lgtest -lgmock)
- c++ (ISO C++ standard  >=14)

# Usage
Copy the cpp_free_mock directory to your project include directory, make sure the build tool can find the header.

`cp -r cpp_free_mock ${CURRENT_SOURCE_DIR}/include/`
- Blade: TODO
- CMakeLists.txt:
```Cmake
include_directories(
    ${CURRENT_SOURCE_DIR}/include/
)
```
- Makefile:
```Makefile
CPPFLAGS += -I ${CURRENT_SOURCE_DIR}/include/ 
```



# Compile commands


# Example
1. Without main function
```cpp
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "cpp_free_mock/cpp_free_mock.h"

using namespace ::testing;

std::string func() {
    return "Non mocked.";
}

TEST(HelloWorld, First) {
    EXPECT_CALL(*MOCKER(func), MOCK_FUNCTION())
        .Times(Exactly(1))
        .WillOnce(Return("Hello world."));
    EXPECT_EQ("Hello world.", func());
}
```
Compile the test file without main function
```
g++ -O2 -std=c++14 hello_world.cpp -I .. -lgtest -lgtest_main -lgmock
```

2. With main function
```cpp
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "cpp_free_mock/cpp_free_mock.h"

using namespace ::testing;

std::string func() {
    return "Non mocked.";
}

TEST(HelloWorld, First) {
    EXPECT_CALL(*MOCKER(func), MOCK_FUNCTION())
        .Times(Exactly(1))
        .WillOnce(Return("Hello world."));
    EXPECT_EQ("Hello world.", func());
}

int main(int argc, char *argv[]){
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  
}
```
Compile the test file with main function, no need to link gtest_main
```
g++ -O2 -std=c++14 hello_world.cpp -I .. -lgtest -lgmock
```
