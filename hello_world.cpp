// Copyright 2014 Louix Gu
// Author: gzc9047@gmail.com (Louix Gu)

// CppFreeMock: a tool for mock global function, member function, class static function.
//
// Hello world.

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
