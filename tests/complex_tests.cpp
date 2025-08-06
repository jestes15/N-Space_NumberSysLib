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

using hypercomplex::complex;

TEST(ComplexTest, DefaultConstructor)
{
  const complex<float> dut;
  EXPECT_FLOAT_EQ(dut.real(), 0.0f);
  EXPECT_FLOAT_EQ(dut.imag(), 0.0f);
}

TEST(ComplexTest, UnderlyingTypeConstructor)
{
  const complex<double> dut(3.5, -1.2);
  EXPECT_DOUBLE_EQ(dut.real(), 3.5);
  EXPECT_DOUBLE_EQ(dut.imag(), -1.2);
}

TEST(ComplexTest, ConvertibleTypesConstructor)
{
  const complex<float> dut(2, 7);
  EXPECT_FLOAT_EQ(dut.real(), 2.0f);
  EXPECT_FLOAT_EQ(dut.imag(), 7.0f);
}

TEST(ComplexTest, CrossTypeConstructor)
{
  const complex<float> dut1(3, 4);
  const complex<double> dut2(dut1);
  EXPECT_DOUBLE_EQ(dut2.real(), 3.0);
  EXPECT_DOUBLE_EQ(dut2.imag(), 4.0);
}

//
// Assignment: scalar and complex
//
TEST(ComplexAssignmentOperators, AssignScalar)
{
  complex<float> dut;
  dut = 2.5f;
  EXPECT_FLOAT_EQ(dut.real(), 2.5f);
  EXPECT_FLOAT_EQ(dut.imag(), 0.0f);
}

TEST(ComplexAssignmentOperators, AssignSameType)
{
  complex<float> dut1(1.2f, 3.4f);
  complex<float> dut2;
  dut2 = dut1;
  EXPECT_FLOAT_EQ(dut2.real(), 1.2f);
  EXPECT_FLOAT_EQ(dut2.imag(), 3.4f);
  EXPECT_FLOAT_EQ(dut1.real(), 1.2f);
  EXPECT_FLOAT_EQ(dut1.imag(), 3.4f);
}

TEST(ComplexAssignmentOperators, AssignCrossType)
{
  complex<float> dut1(2, 3);
  complex<float> dut2;
  dut2 = dut1;
  EXPECT_FLOAT_EQ(dut2.real(), 2.0f);
  EXPECT_FLOAT_EQ(dut2.imag(), 3.0f);
  EXPECT_FLOAT_EQ(dut1.real(), 2.0f);
  EXPECT_FLOAT_EQ(dut1.imag(), 3.0f);
}

TEST(ComplexAssignmentOperators, AssignCrossTypeWithLiteral)
{
  using namespace hypercomplex::complex_literals;
  const complex<float> dut = 3.0f + 4.0if;

  EXPECT_FLOAT_EQ(dut.real(), 3.0f);
  EXPECT_FLOAT_EQ(dut.imag(), 4.0f);
}

//
// Compound assignment with scalar
//
TEST(ComplexCompoundOperators, PlusEqualsScalar)
{
  complex<float> dut(1.0f, 2.0f);
  dut += 3.0f;
  std::complex<float> ref(1.0f, 2.0f);
  ref += 3.0f;

  EXPECT_FLOAT_EQ(dut.real(), ref.real());
  EXPECT_FLOAT_EQ(dut.imag(), ref.imag());
}

TEST(ComplexCompoundOperators, MinusEqualsScalar)
{
  complex<float> dut(5.0f, 2.0f);
  dut -= 1.5f;
  std::complex<float> ref(5.0f, 2.0f);
  ref -= 1.5f;

  EXPECT_FLOAT_EQ(dut.real(), ref.real());
  EXPECT_FLOAT_EQ(dut.imag(), ref.imag());
}

TEST(ComplexCompoundOperators, TimesEqualsScalar)
{
  complex<float> dut(1.0f, 2.0f);
  dut *= 2.0f;

  std::complex<float> ref(1.0f, 2.0f);
  ref *= 2.0f;

  EXPECT_FLOAT_EQ(dut.real(), ref.real());
  EXPECT_FLOAT_EQ(dut.imag(), ref.imag());
}

TEST(ComplexCompoundOperators, DivideEqualsScalar)
{
  complex<float> dut(4.0f, 2.0f);
  dut /= 2.0f;

  std::complex<float> ref(4.0f, 2.0f);
  ref /= 2.0f;

  EXPECT_FLOAT_EQ(dut.real(), ref.real());
  EXPECT_FLOAT_EQ(dut.imag(), ref.imag());
}

// //
// // Compound assignment with complex
// //
TEST(ComplexCompoundOperators, PlusEqualsComplex)
{
  complex<float> dut1(1.0f, 2.0f);
  complex<float> dut2(3.0f, -1.0f);
  dut1 += dut2;

  std::complex<float> ref1(1.0f, 2.0f);
  std::complex<float> ref2(3.0f, -1.0f);
  ref1 += ref2;

  EXPECT_FLOAT_EQ(dut1.real(), ref1.real());
  EXPECT_FLOAT_EQ(dut1.imag(), ref1.imag());
  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexCompoundOperators, MinusEqualsComplex)
{
  complex<float> dut1(5.0f, 2.0f);
  complex<float> dut2(3.0f, 1.0f);
  dut1 -= dut2;

  std::complex<float> ref1(5.0f, 2.0f);
  std::complex<float> ref2(3.0f, 1.0f);
  ref1 -= ref2;

  EXPECT_FLOAT_EQ(dut1.real(), ref1.real());
  EXPECT_FLOAT_EQ(dut1.imag(), ref1.imag());
  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexCompoundOperators, TimesEqualsComplex)
{
  complex<float> dut1(1.0f, 2.0f);
  complex<float> dut2(3.0f, 4.0f);
  dut1 *= dut2;

  complex<float> ref1(1.0f, 2.0f);
  complex<float> ref2(3.0f, 4.0f);
  ref1 *= ref2;

  EXPECT_FLOAT_EQ(dut1.real(), ref1.real());
  EXPECT_FLOAT_EQ(dut1.imag(), ref1.imag());
  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexCompoundOperators, DivideEqualsComplex)
{
  complex<float> dut1(1.0f, 2.0f);
  complex<float> dut2(3.0f, 4.0f);
  dut1 /= dut2;

  complex<float> ref1(1.0f, 2.0f);
  complex<float> ref2(3.0f, 4.0f);
  ref1 /= ref2;

  EXPECT_FLOAT_EQ(dut1.real(), ref1.real());
  EXPECT_FLOAT_EQ(dut1.imag(), ref1.imag());
  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

// //
// // Binary ops: complex op complex
// //
TEST(ComplexOperators, AddComplex)
{
  complex<float> dut1(2.0f, 1.0f);
  complex<float> dut2(3.0f, 4.0f);
  auto dut3 = dut1 + dut2;

  complex<float> ref1(2.0f, 1.0f);
  complex<float> ref2(3.0f, 4.0f);
  auto ref3 = ref1 + ref2;

  EXPECT_FLOAT_EQ(dut3.real(), ref3.real());
  EXPECT_FLOAT_EQ(dut3.imag(), ref3.imag());
}

TEST(ComplexOperators, SubComplex)
{
  complex<float> dut1(4.0f, 3.0f);
  complex<float> dut2(1.0f, 2.0f);
  auto dut3 = dut1 - dut2;

  std::complex<float> ref1(4.0f, 3.0f);
  std::complex<float> ref2(1.0f, 2.0f);
  auto ref3 = ref1 - ref2;

  EXPECT_FLOAT_EQ(dut3.real(), ref3.real());
  EXPECT_FLOAT_EQ(dut3.imag(), ref3.imag());
}

TEST(ComplexOperators, MulComplex)
{
  complex<float> dut1(4.0f, 3.0f);
  complex<float> dut2(1.0f, 2.0f);
  auto dut3 = dut1 * dut2;

  std::complex<float> ref1(4.0f, 3.0f);
  std::complex<float> ref2(1.0f, 2.0f);
  auto ref3 = ref1 * ref2;

  EXPECT_FLOAT_EQ(dut3.real(), ref3.real());
  EXPECT_FLOAT_EQ(dut3.imag(), ref3.imag());
}

TEST(ComplexOperators, DivComplex)
{
  complex<float> dut1(4.0f, 3.0f);
  complex<float> dut2(1.0f, 2.0f);
  auto dut3 = dut1 / dut2;

  std::complex<float> ref1(4.0f, 3.0f);
  std::complex<float> ref2(1.0f, 2.0f);
  auto ref3 = ref1 / ref2;

  EXPECT_FLOAT_EQ(dut3.real(), ref3.real());
  EXPECT_FLOAT_EQ(dut3.imag(), ref3.imag());
}

// //
// // Binary ops: complex op scalar
// //
TEST(ComplexOperators, AddScalarRight)
{
  complex<float> dut1(1.0f, 2.0f);
  auto dut2 = dut1 + 3.0f;

  std::complex<float> ref1(1.0f, 2.0f);
  auto ref2 = ref1 + 3.0f;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexOperators, SubScalarRight)
{
  complex<float> dut1(5.0f, 1.0f);
  auto dut2 = dut1 - 3.0f;

  std::complex<float> ref1(5.0f, 1.0f);
  auto ref2 = ref1 - 3.0f;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexOperators, MulScalarRight)
{
  complex<float> dut1(2.0f, 3.0f);
  auto dut2 = dut1 * 2.0f;

  std::complex<float> ref1(2.0f, 3.0f);
  auto ref2 = ref1 * 2.0f;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexOperators, DivScalarRight)
{
  complex<float> dut1(4.0f, 2.0f);
  auto dut2 = dut1 / 2.0f;

  std::complex<float> ref1(4.0f, 2.0f);
  auto ref2 = ref1 / 2.0f;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

//
// Binary ops: scalar op complex
//
TEST(ComplexOperators, AddScalarLeft)
{
  complex<float> dut1(1.0f, 2.0f);
  auto dut2 = 3.0f + dut1;

  std::complex<float> ref1(1.0f, 2.0f);
  auto ref2 = 3.0f + ref1;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexOperators, SubScalarLeft)
{
  complex<float> dut1(1.0f, 2.0f);
  auto dut2 = 3.0f - dut1;

  std::complex<float> ref1(1.0f, 2.0f);
  auto ref2 = 3.0f - ref1;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag()) << dut2 << " " << ref2 << "\n";
}

TEST(ComplexOperators, MulScalarLeft)
{
  complex<float> dut1(2.0f, -1.0f);
  auto dut2 = 3.0f * dut1;

  std::complex<float> ref1(2.0f, -1.0f);
  auto ref2 = 3.0f * ref1;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
}

TEST(ComplexOperators, DivScalarLeft)
{
  complex<float> dut1(4.27f, 19.235f);
  auto dut2 = 2.0f / dut1;

  std::complex<float> ref1(4.27f, 19.235f);
  auto ref2 = 2.0f / ref1;

  EXPECT_FLOAT_EQ(dut2.real(), ref2.real());
  EXPECT_FLOAT_EQ(dut2.imag(), ref2.imag());
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