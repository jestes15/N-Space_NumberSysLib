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
//      the ISO C++ Standard in section 28.4.
//      https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4928.pdf
//
// header-end --------------------------------------------

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>
#include <type_traits>

namespace hypercomplex
{
// Constants
constexpr long double __pi = 3.1415926535897932384626433832795028L;
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
template <typename _UnderlyingType> complex<_UnderlyingType> acos(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> sin(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> asin(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> tan(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> atan(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> cot(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> acot(const complex<_UnderlyingType> &);

template <typename _UnderlyingType> complex<_UnderlyingType> cosh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> acosh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> sinh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> asinh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> tanh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> atanh(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> coth(const complex<_UnderlyingType> &);
template <typename _UnderlyingType> complex<_UnderlyingType> acoth(const complex<_UnderlyingType> &);
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

template <typename _UnderlyingType> class complex
{
  static_assert(std::is_floating_point<_UnderlyingType>::value, "_UnderlyingType must be a floating-point type");

private:
  // z = _real + i * _image
  _UnderlyingType _real, _imag;

protected:
public:
  constexpr complex(const _UnderlyingType &_r = _UnderlyingType(), const _UnderlyingType &_i = _UnderlyingType())
      : _real(_r), _imag(_i)
  {
  }
  template <typename _AType, typename _BType>
  constexpr complex(const _AType &_r = _AType(), const _BType &_i = _BType())
      : _real(static_cast<_UnderlyingType>(_r)), _imag(static_cast<_UnderlyingType>(_i))
  {
  }
  constexpr complex(const complex &) = default;
  template <class type>
  constexpr complex(const complex<type> &_z)
      : _real(static_cast<_UnderlyingType>(_z.real())), _imag(static_cast<_UnderlyingType>(_z.imag()))
  {
  }

  inline constexpr _UnderlyingType
  real() const
  {
    return _real;
  }
  inline constexpr void
  real(_UnderlyingType _val)
  {
    _real = _val;
  }
  inline constexpr _UnderlyingType
  imag() const
  {
    return _imag;
  }
  inline constexpr void
  imag(_UnderlyingType _val)
  {
    _imag = _val;
  }

  constexpr complex &
  operator=(const _UnderlyingType &rhs)
  {
    _real = rhs;
    _imag = _UnderlyingType();
    return *this;
  }
  inline constexpr complex &
  operator+=(const _UnderlyingType &rhs)
  {
    _real += rhs;
    return *this;
  }
  inline constexpr complex &
  operator-=(const _UnderlyingType &rhs)
  {
    _real -= rhs;
    return *this;
  }
  inline constexpr complex &
  operator*=(const _UnderlyingType &rhs)
  {
    _real *= rhs;
    _imag *= rhs;
    return *this;
  }
  inline constexpr complex &
  operator/=(const _UnderlyingType &rhs)
  {
    _real /= rhs;
    _imag /= rhs;
    return *this;
  }

  constexpr complex &operator=(const complex &rhs) = default;
  template <class _Type>
  constexpr complex &
  operator=(const complex<_Type> &rhs)
  {
    _real = rhs.real();
    _imag = rhs.imag();
    return *this;
  }
  template <class _Type>
  inline constexpr complex &
  operator+=(const complex<_Type> &rhs)
  {
    _real += rhs.real();
    _imag += rhs.imag();
    return *this;
  }
  template <class _Type>
  inline constexpr complex &
  operator-=(const complex<_Type> &rhs)
  {
    _real -= rhs.real();
    _imag -= rhs.imag();
    return *this;
  }
  template <class _Type>
  inline constexpr complex &
  operator*=(const complex<_Type> &rhs)
  {
    _imag = _real * rhs.imag() + _imag * rhs.real();
    _real = _real * rhs.real() - _imag * rhs.imag();
    return *this;
  }

  // TODO: Fix the math
  template <class _Type>
  inline constexpr complex &
  operator/=(const complex<_Type> &rhs)
  {
    const _UnderlyingType _r = _real * rhs.real() + _imag * rhs.imag();
    const _UnderlyingType _norm = norm(rhs);
    _imag = (_imag * rhs.real() - _real * rhs.imag()) / _norm;
    _real = _r / _norm;
    return *this;
  }
};

inline namespace literals
{
inline namespace complex_literals
{
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4455)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuser-defined-literals"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"
#endif

constexpr complex<float>
operator""if(long double _num)
{
  return complex<float>{ 0.0f, static_cast<float>(_num) };
}
constexpr complex<float>
operator""if(unsigned long long _num)
{
  return complex<float>{ 0.0f, static_cast<float>(_num) };
}
constexpr complex<double>
operator""i(long double _num)
{
  return complex<float>{ 0.0, static_cast<double>(_num) };
}
constexpr complex<double>
operator""i(unsigned long long _num)
{
  return complex<float>{ 0.0, static_cast<double>(_num) };
}
constexpr complex<long double>
operator""il(long double _num)
{
  return complex<float>{ 0.0, static_cast<long double>(_num) };
}
constexpr complex<long double>
operator""il(unsigned long long _num)
{
  return complex<float>{ 0.0, static_cast<long double>(_num) };
}

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

} // namespace complex_literals
} // namespace literals

// Addition Operators
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator+(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
  return complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator+(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
  return complex(lhs.real() + rhs, lhs.imag());
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator+(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
  return complex(lhs + rhs.real(), rhs.imag());
}

// Subtraction Operators
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator-(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
  return complex(lhs.real() - rhs.real(), lhs.imag() - rhs.imag());
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator-(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
  return complex(lhs.real() - rhs, lhs.imag());
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator-(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
  return complex(lhs - rhs.real(), -rhs.imag());
}

// Multiplication Operators
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator*(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
  _UnderlyingType _r = lhs.real() * rhs.real() - lhs.imag() * rhs.imag();
  _UnderlyingType _i = lhs.real() * rhs.imag() + lhs.imag() * rhs.real();
  complex<_UnderlyingType> _t(_r, _i);
  return _t;
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator*(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
  _UnderlyingType _r = lhs.real() * rhs;
  _UnderlyingType _i = lhs.imag() * rhs;
  complex<_UnderlyingType> _t(_r, _i);
  return _t;
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator*(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
  _UnderlyingType _r = lhs * rhs.real();
  _UnderlyingType _i = lhs * rhs.imag();
  complex<_UnderlyingType> _t(_r, _i);
  return _t;
}

// Division Operators
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator/(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
  complex<_UnderlyingType> _r = lhs;
  return _r /= rhs;
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator/(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
  complex<_UnderlyingType> _r = lhs;
  return _r /= rhs;
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator/(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
  complex<_UnderlyingType> _r = lhs;
  return _r /= rhs;
}

// Unary Operators
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator+(const complex<_UnderlyingType> &_z)
{
  return _z;
}
template <typename _UnderlyingType>
inline constexpr complex<_UnderlyingType>
operator-(const complex<_UnderlyingType> &_z)
{
  return complex<_UnderlyingType>(-_z.real(), -_z.imag());
}

// Equality Operators
template <typename _UnderlyingType>
inline constexpr bool
operator==(const complex<_UnderlyingType> &rhs, const complex<_UnderlyingType> &lhs)
{
  return (rhs.real() == lhs.real()) && (rhs.imag() == lhs.imag());
}
template <typename _UnderlyingType>
inline constexpr bool
operator==(const complex<_UnderlyingType> &rhs, const _UnderlyingType &lhs)
{
  return (rhs.real() == lhs.real()) && (rhs.imag() == 0);
}

// Streaming Operators
// TODO: Implement the extraction operator
template <class _UnderlyingType, class charT, class traits>
std::basic_istream<charT, traits> &
operator>>(std::basic_istream<charT, traits> &is, complex<_UnderlyingType> &rhs)
{
  return is;
}
template <class _UnderlyingType, class charT, class traits>
std::basic_ostream<charT, traits> &
operator<<(std::basic_ostream<charT, traits> &o, const complex<_UnderlyingType> &rhs)
{
  o << "(" << rhs.real() << "," << rhs.imag() << ")";
  return o;
}

// Values
template <class _UnderlyingType>
constexpr _UnderlyingType
real(const complex<_UnderlyingType> &_z)
{
  return _z.real();
}
template <class _UnderlyingType>
constexpr _UnderlyingType
imag(const complex<_UnderlyingType> &_z)
{
  return _z.imag();
}

// Mathematical Functions
template <typename _UnderlyingType>
_UnderlyingType
abs(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _r = _z.real();
  _UnderlyingType _i = _z.imag();
  return std::sqrt(_r * _r + _i * _i);
}
template <typename _UnderlyingType>
_UnderlyingType
arg(const complex<_UnderlyingType> &_z)
{
  return std::atan2(_z.imag(), _z.real());
}
template <typename _UnderlyingType>
constexpr _UnderlyingType
norm(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _x = _z.real();
  _UnderlyingType _y = _z.imag();
  return _x * _x + _y * _y;
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType>
conj(const complex<_UnderlyingType> &_z)
{
  return complex<_UnderlyingType>(_z.real(), -_z.imag());
}
template <class _UnderlyingType>
complex<_UnderlyingType>
proj(const complex<_UnderlyingType> &_z)
{
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
polar(const _UnderlyingType &_rho, const _UnderlyingType &_theta)
{
  if (!std::isinf(_theta) && !std::isnan(_rho)) {
    if (std::isinf(_rho))
  }
  return complex<_UnderlyingType>(0.0f, 0.0f);
}

// Transcendentals
template <typename _UnderlyingType>
complex<_UnderlyingType>
cos(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  _UnderlyingType _real = std::cos(_a) * std::cosh(_b);
  _UnderlyingType _imag = -1.0f * std::sin(_a) * std::sinh(_b);
  return complex<_UnderlyingType>(_real, _imag);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
acos(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
sin(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  _UnderlyingType _r = std::sin(_a) * std::cosh(_b);
  _UnderlyingType _i = std::cos(_a) * std::sinh(_b);
  return complex<_UnderlyingType>(_r, _i);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
asin(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
tan(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  complex<_UnderlyingType> _numerator = std::tan(_a) + 1.0if * std::tanh(_b);
  complex<_UnderlyingType> _denomerator = 1.0f - 1.0if * std::tan(_a) * std::tanh(_b);

  return complex<_UnderlyingType>(_numerator / _denomerator);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
atan(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
cot(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  complex<_UnderlyingType> _numerator = 1.0f + 1.0if * (std::cos(_a) / std::sin(_a)) * (std::cosh(_b) / std::sinh(_b));
  complex<_UnderlyingType> _denominator = (std::cos(_a) / std::sin(_a)) - 1.0if * (std::cosh(_b) / std::sinh(_b));
  return complex<_UnderlyingType>(-1.0f * _numerator / _denominator);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
acot(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
cosh(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  _UnderlyingType _r = std::cosh(_a) * std::cos(_b);
  _UnderlyingType _i = std::sinh(_a) * std::sin(_b);
  return complex<_UnderlyingType>(_r, _i);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
acosh(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
sinh(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  _UnderlyingType _r = std::sinh(_a) * std::cos(_b);
  _UnderlyingType _i = std::cosh(_a) * std::sin(_b);
  return complex<_UnderlyingType>(_r, _i);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
asinh(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
tanh(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  _UnderlyingType _numerator = std::sinh(_a) * std::cos(_b) + 1.0if * std::cosh(_a) * std::sin(_b);
  _UnderlyingType _denominator = std::cosh(_a) * std::cos(_b) + 1.0if * std::sinh(_a) * std::sin(_b);
  return complex<_UnderlyingType>(_numerator / _denominator);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
atanh(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
coth(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
  _UnderlyingType _numerator = std::cosh(_a) * std::cos(_b) + 1.0if * std::sinh(_a) * std::sin(_b);
  _UnderlyingType _denominator = std::sinh(_a) * std::cos(_b) + 1.0if * std::cosh(_a) * std::sin(_b);
  return complex<_UnderlyingType>(_numerator / _denominator);
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
acoth(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
exp(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
log(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
log10(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
template <typename _UnderlyingType, typename _ExponentialType>
complex<_UnderlyingType>
pow(const complex<_UnderlyingType> &_z, const _ExponentialType &exp)
{
}
template <typename _UnderlyingType, typename _BaseType>
complex<_UnderlyingType>
pow(const _BaseType &, const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
pow(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType>
complex<_UnderlyingType>
sqrt(const complex<_UnderlyingType> &_z)
{
  _UnderlyingType _a = _z.real(), _b = _z.imag();
}
} // namespace hypercomplex
#endif // COMPLEX_HPP

// footer-begin ------------------------------------------
// default.C++
// File       : complex.hpp
// footer-end --------------------------------------------