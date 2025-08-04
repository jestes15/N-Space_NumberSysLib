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

using hypercomplex::complex;

template <typename T>
bool
almost_equal(T a, T b, T eps = static_cast<T>(1e-6))
{
  return std::abs(a - b) < eps;
}

template <typename T>
void
expect_complex_eq(const complex<T> &c, T real, T imag,
		  T eps = static_cast<T>(1e-6))
{
  EXPECT_TRUE(almost_equal(c.real(), real, eps));
  EXPECT_TRUE(almost_equal(c.imag(), imag, eps));
}

TEST(ComplexTest, DefaultConstructor)
{
  const complex<float> c;
  EXPECT_FLOAT_EQ(c.real(), 0.0f);
  EXPECT_FLOAT_EQ(c.imag(), 0.0f);
}

TEST(ComplexTest, UnderlyingTypeConstructor)
{
  const complex<double> c(3.5, -1.2);
  EXPECT_DOUBLE_EQ(c.real(), 3.5);
  EXPECT_DOUBLE_EQ(c.imag(), -1.2);
}

TEST(ComplexTest, ConvertibleTypesConstructor)
{
  const complex<float> c(2, 7);
  EXPECT_FLOAT_EQ(c.real(), 2.0f);
  EXPECT_FLOAT_EQ(c.imag(), 7.0f);
}

TEST(ComplexTest, CrossTypeConstructor)
{
  const complex<float> ci(3, 4);
  const complex<double> cd(ci);
  EXPECT_DOUBLE_EQ(cd.real(), 3.0);
  EXPECT_DOUBLE_EQ(cd.imag(), 4.0);
}

//
// Assignment: scalar and complex
//
TEST(ComplexOperators, AssignScalar)
{
  complex<float> c;
  c = 2.5f;
  expect_complex_eq(c, 2.5f, 0.0f);
}

TEST(ComplexOperators, AssignSameType)
{
  complex<float> a(1.2f, 3.4f);
  complex<float> b;
  b = a;
  expect_complex_eq(b, 1.2f, 3.4f);
}

TEST(ComplexOperators, AssignCrossType)
{
  complex<float> a(2, 3);
  complex<float> b;
  b = a;
  expect_complex_eq(b, 2.0f, 3.0f);
}

//
// Compound assignment with scalar
//
TEST(ComplexOperators, PlusEqualsScalar)
{
  complex<float> c(1.0f, 2.0f);
  c += 3.0f;
  expect_complex_eq(c, 4.0f, 2.0f);
}

TEST(ComplexOperators, MinusEqualsScalar)
{
  complex<float> c(5.0f, 2.0f);
  c -= 1.5f;
  expect_complex_eq(c, 3.5f, 2.0f);
}

TEST(ComplexOperators, TimesEqualsScalar)
{
  complex<float> c(1.0f, 2.0f);
  c *= 2.0f;
  expect_complex_eq(c, 2.0f, 4.0f);
}

TEST(ComplexOperators, DivideEqualsScalar)
{
  complex<float> c(4.0f, 2.0f);
  c /= 2.0f;
  expect_complex_eq(c, 2.0f, 1.0f);
}

//
// Compound assignment with complex
//
TEST(ComplexOperators, PlusEqualsComplex)
{
  complex<float> a(1.0f, 2.0f);
  complex<float> b(3.0f, -1.0f);
  a += b;
  expect_complex_eq(a, 4.0f, 1.0f);
}

TEST(ComplexOperators, MinusEqualsComplex)
{
  complex<float> a(5.0f, 2.0f);
  complex<float> b(3.0f, 1.0f);
  a -= b;
  expect_complex_eq(a, 2.0f, 1.0f);
}

TEST(ComplexOperators, TimesEqualsComplex)
{
  complex<float> a(1.0f, 2.0f);
  complex<float> b(3.0f, 4.0f);
  a *= b; // (1+2i)*(3+4i) = -5 + 10i
  expect_complex_eq(a, -5.0f, 10.0f);
}

TEST(ComplexOperators, DivideEqualsComplex)
{
  complex<float> a(1.0f, 2.0f);
  complex<float> b(3.0f, 4.0f);
  a /= b; // (1+2i)/(3+4i) = 11/25 + 2/25 i
  expect_complex_eq(a, 0.44f, 0.08f, 1e-4f);
}

//
// Binary ops: complex op complex
//
TEST(ComplexOperators, AddComplex)
{
  complex<float> a(2.0f, 1.0f);
  complex<float> b(3.0f, 4.0f);
  auto c = a + b;
  expect_complex_eq(c, 5.0f, 5.0f);
}

TEST(ComplexOperators, SubComplex)
{
  complex<float> a(4.0f, 3.0f);
  complex<float> b(1.0f, 2.0f);
  auto c = a - b;
  expect_complex_eq(c, 3.0f, 1.0f);
}

TEST(ComplexOperators, MulComplex)
{
  complex<float> a(2.0f, 3.0f);
  complex<float> b(4.0f, -1.0f);
  auto c = a * b; // (2+3i)*(4-1i) = 11 + 10i
  expect_complex_eq(c, 11.0f, 10.0f);
}

TEST(ComplexOperators, DivComplex)
{
  complex<float> a(1.0f, 2.0f);
  complex<float> b(2.0f, 1.0f);
  auto c = a / b; // (1+2i)/(2+1i) = 0.8 + 0.6i
  expect_complex_eq(c, 0.8f, 0.6f, 1e-4f);
}

//
// Binary ops: complex op scalar
//
TEST(ComplexOperators, AddScalarRight)
{
  complex<float> a(1.0f, 2.0f);
  auto c = a + 3.0f;
  expect_complex_eq(c, 4.0f, 2.0f);
}

TEST(ComplexOperators, SubScalarRight)
{
  complex<float> a(5.0f, 1.0f);
  auto c = a - 2.0f;
  expect_complex_eq(c, 3.0f, 1.0f);
}

TEST(ComplexOperators, MulScalarRight)
{
  complex<float> a(2.0f, 3.0f);
  auto c = a * 2.0f;
  expect_complex_eq(c, 4.0f, 6.0f);
}

TEST(ComplexOperators, DivScalarRight)
{
  complex<float> a(4.0f, 2.0f);
  auto c = a / 2.0f;
  expect_complex_eq(c, 2.0f, 1.0f);
}

//
// Binary ops: scalar op complex
//
TEST(ComplexOperators, AddScalarLeft)
{
  complex<float> a(1.0f, 2.0f);
  auto c = 3.0f + a;
  expect_complex_eq(c, 4.0f, 2.0f);
}

TEST(ComplexOperators, SubScalarLeft)
{
  complex<float> a(1.0f, 2.0f);
  auto c = 3.0f - a;
  expect_complex_eq(c, 2.0f, -2.0f);
}

TEST(ComplexOperators, MulScalarLeft)
{
  complex<float> a(2.0f, -1.0f);
  auto c = 2.0f * a;
  expect_complex_eq(c, 4.0f, -2.0f);
}

TEST(ComplexOperators, DivScalarLeft)
{
  complex<float> a(1.0f, 1.0f);
  auto c = 2.0f / a;
  expect_complex_eq(c, 1.0f, -1.0f, 1e-4f);
}

int
main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// footer-begin ------------------------------------------
// default.C++
// File       : complex_tests.cpp
// footer-end --------------------------------------------