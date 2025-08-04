// header-begin ------------------------------------------
// File       : complex_tests.cpp
//
// Author      : Unknown Author
// Email       : unknown@example.com
//
// Created on  : 8/3/2025
//
// header-end --------------------------------------------

#include <gtest/gtest.h>

#include "hypercomplex/complex.hpp"

#include <complex>

TEST(complex, DefaultConstructor) {
    const hypercomplex::complex<float> complex_number;

    EXPECT_EQ(complex_number.real(), 0.0f);
    EXPECT_EQ(complex_number.imag(), 0.0f);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// footer-begin ------------------------------------------
// default.C++
// File       : complex_tests.cpp
// footer-end --------------------------------------------