// header-begin ------------------------------------------
// File       : complex.hpp
//
// Author      : Joshua E
// Email       : estesjn2020@gmail.com
//
// Created on  : 8/2/2025
//
// Comments:
//      This header file is based on information from
//      the ISO C++ Standard in section 26.4.
//      https://isocpp.org/files/papers/N4860.pdf
//
// header-end --------------------------------------------

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <istream>
#include <ostream>
#include <type_traits>

namespace hypercomplex
{
// Constants
constexpr long double __pi_2 = 1.5707963267948966192313216916397514L;

// Class Forward Decleration
template <typename _UnderlyingType> class complex;

// Addition Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator+(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator+(const complex<_UnderlyingType> &, const _UnderlyingType &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator+(const _UnderlyingType &, const complex<_UnderlyingType> &);

// Subtraction Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator-(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator-(const complex<_UnderlyingType> &, const _UnderlyingType &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator-(const _UnderlyingType &, const complex<_UnderlyingType> &);

// Multiplication Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator*(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator*(const complex<_UnderlyingType> &, const _UnderlyingType &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator*(const _UnderlyingType &, const complex<_UnderlyingType> &);

// Division Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator/(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator/(const complex<_UnderlyingType> &, const _UnderlyingType &);
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator/(const _UnderlyingType &, const complex<_UnderlyingType> &);

// Unary Operators
template <typename _UnderlyingType> constexpr complex<_UnderlyingType> operator+(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> constexpr complex<_UnderlyingType> operator-(const complex<_UnderlyingType> &);

// Equality Operators
template <typename _UnderlyingType>
constexpr bool operator==(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &);
template <typename _UnderlyingType>
constexpr bool operator==(const complex<_UnderlyingType> &, const _UnderlyingType &);

// Streaming Operators
template <class _UnderlyingType, class charT, class traits>
std::basic_istream<charT, traits> &operator>>(std::basic_istream<charT, traits> &, complex<_UnderlyingType> &);
template <class _UnderlyingType, class charT, class traits>
std::basic_ostream<charT, traits> &operator<<(std::basic_ostream<charT, traits> &, const complex<_UnderlyingType> &);

// Values
template <class _UnderlyingType> constexpr _UnderlyingType real(const complex<_UnderlyingType> &);
template <class _UnderlyingType> constexpr _UnderlyingType imag(const complex<_UnderlyingType> &);

// Mathematical Functions
template <typename _UnderlyingType> _UnderlyingType abs(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> _UnderlyingType arg(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> constexpr _UnderlyingType norm(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> constexpr complex<_UnderlyingType> conj(const complex<_UnderlyingType> &);
template <class _UnderlyingType> complex<_UnderlyingType> proj(const complex<_UnderlyingType> &);
template <typename _UnderlyingType>
complex<_UnderlyingType> polar(const _UnderlyingType &, const _UnderlyingType & = 0);

// Transcendentals
template <typename _UnderlyingType> complex<_UnderlyingType> cos(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> cosh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> acos(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> acosh(const complex<_UnderlyingType> &);

template <typename _UnderlyingType> complex<_UnderlyingType> sin(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> sinh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> asin(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> asinh(const complex<_UnderlyingType> &);

template <typename _UnderlyingType> complex<_UnderlyingType> tan(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> tanh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> atan(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> atanh(const complex<_UnderlyingType> &);

template <typename _UnderlyingType> complex<_UnderlyingType> exp(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> log(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> log10(const complex<_UnderlyingType> &);
template <typename _UnderlyingType, typename _ExponentialType>
complex<_UnderlyingType> pow(const complex<_UnderlyingType> &, const _ExponentialType &);
template <typename _UnderlyingType, typename _BaseType>
complex<_UnderlyingType> pow(const _BaseType &, const complex<_UnderlyingType> &);
template <typename _UnderlyingType>
complex<_UnderlyingType> pow(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> sqrt(const complex<_UnderlyingType> &);

inline namespace literals
{
inline namespace complex_literals
{
constexpr complex<long double> operator""il(long double);
constexpr complex<long double> operator""il(unsigned long long);
constexpr complex<double> operator""i(long double);
constexpr complex<double> operator""i(unsigned long long);
constexpr complex<float> operator""if(long double);
constexpr complex<float> operator""if(unsigned long long);

} // namespace complex_literals
} // namespace literals

template <typename _UnderlyingType> class complex
{
    static_assert(std::is_floating_point<_UnderlyingType>::value, "_UnderlyingType must be a floating-point type");

  private:
    // z = a + ib
    _UnderlyingType a, b;

  protected:
  public:
    template <typename _AType, typename _BType>
        requires(std::is_arithmetic_v<_AType> && std::is_arithmetic_v<_BType>)
    complex(_AType a, _BType b)
    {
        a = static_cast<_UnderlyingType>(a);
        b = static_cast<_UnderlyingType>(b);
    }
};

} // namespace hypercomplex
#endif // COMPLEX_HPP

// footer-begin ------------------------------------------
// default.C++
// File       : complex.hpp
// footer-end --------------------------------------------