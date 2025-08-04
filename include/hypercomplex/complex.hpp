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
//      https://isocpp.org/files/papers/N4860.pdf
//
// header-end --------------------------------------------

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>
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

// inline namespace literals
// {
//   inline namespace complex_literals
//   {
//     constexpr complex<long double> operator""il(long double);
//     constexpr complex<long double> operator""il(unsigned long long);
//     constexpr complex<double> operator""i(long double);
//     constexpr complex<double> operator""i(unsigned long long);
//     constexpr complex<float> operator""if (long double);
//     constexpr complex<float> operator""if (unsigned long long);

//   } // namespace complex_literals
// } // namespace literals

template <typename _UnderlyingType> class complex
{
    static_assert(std::is_floating_point<_UnderlyingType>::value, "_UnderlyingType must be a floating-point type");
    // typedef _UnderlyingType value_type;

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

    constexpr _UnderlyingType real() const
    {
        return _real;
    }
    constexpr void real(_UnderlyingType _val)
    {
        _real = _val;
    }
    constexpr _UnderlyingType imag() const
    {
        return _imag;
    }
    constexpr void imag(_UnderlyingType _val)
    {
        _imag = _val;
    }

    constexpr complex &operator=(const _UnderlyingType &rhs)
    {
        _real = rhs;
        _imag = _UnderlyingType();
        return *this;
    }
    constexpr complex &operator+=(const _UnderlyingType &rhs)
    {
        _real += rhs;
        return *this;
    }
    constexpr complex &operator-=(const _UnderlyingType &rhs)
    {
        _real -= rhs;
        return *this;
    }
    constexpr complex &operator*=(const _UnderlyingType &rhs)
    {
        _real *= rhs;
        return *this;
    }
    constexpr complex &operator/=(const _UnderlyingType &rhs)
    {
        _real /= rhs;
        return *this;
    }

    constexpr complex &operator=(const complex &rhs) = default;
    template <class _Type> constexpr complex &operator=(const complex<_Type> &rhs)
    {
        _real = rhs.real();
        _imag = rhs.imag();
        return *this;
    }
    template <class _Type> constexpr complex &operator+=(const complex<_Type> &rhs)
    {
        _real += rhs.real();
        _imag += rhs.imag();
        return *this;
    }
    template <class _Type> constexpr complex &operator-=(const complex<_Type> &rhs)
    {
        _real -= rhs.real();
        _imag -= rhs.imag();
        return *this;
    }
    template <class _Type> constexpr complex &operator*=(const complex<_Type> &rhs)
    {
        const _Type _t = _real * rhs.real() - _imag * rhs.imag();
        _imag = _real * rhs.imag() + _imag * rhs.real();
        _real = _t;
        return *this;
    }
    template <class _Type> constexpr complex &operator/=(const complex<_Type> &rhs)
    {
        _real /= rhs.real();
        _imag /= rhs.imag();
        return *this;
    }
};

// Addition Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator+(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
    return complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator+(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
    return complex(lhs.real() + rhs, lhs.imag());
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator+(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
    return complex(lhs + rhs.real(), rhs.imag());
}

// Subtraction Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator-(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
    return complex(lhs.real() - rhs.real(), lhs.imag() - rhs.imag());
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator-(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
    return complex(lhs.real() - rhs, lhs.imag());
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator-(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
    return complex(lhs - rhs.real(), rhs.imag());
}

// Multiplication Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator*(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator*(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator*(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
}

// Division Operators
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator/(const complex<_UnderlyingType> &lhs, const complex<_UnderlyingType> &rhs)
{
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator/(const complex<_UnderlyingType> &lhs, const _UnderlyingType &rhs)
{
}
template <typename _UnderlyingType>
constexpr complex<_UnderlyingType> operator/(const _UnderlyingType &lhs, const complex<_UnderlyingType> &rhs)
{
}

// Unary Operators
template <typename _UnderlyingType> constexpr complex<_UnderlyingType> operator+(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> constexpr complex<_UnderlyingType> operator-(const complex<_UnderlyingType> &)
{
}

// Equality Operators
template <typename _UnderlyingType>
constexpr bool operator==(const complex<_UnderlyingType> &rhs, const complex<_UnderlyingType> &lhs)
{
    return (rhs.real() == lhs.real()) && (rhs.imag() == lhs.imag());
}
template <typename _UnderlyingType>
constexpr bool operator==(const complex<_UnderlyingType> &rhs, const _UnderlyingType &lhs)
{
    return (rhs.real() == lhs.real()) && (rhs.imag() == 0);
}

// Streaming Operators
template <class _UnderlyingType, class charT, class traits>
std::basic_istream<charT, traits> &operator>>(std::basic_istream<charT, traits> &is, complex<_UnderlyingType> &rhs)
{
    return is;
}
template <class _UnderlyingType, class charT, class traits>
std::basic_ostream<charT, traits> &operator<<(std::basic_ostream<charT, traits> &o, const complex<_UnderlyingType> &rhs)
{
    o << "(" << rhs.real() << ", " << rhs.imag() << ")";
    return o;
}

// Values
template <class _UnderlyingType> constexpr _UnderlyingType real(const complex<_UnderlyingType> &)
{
}
template <class _UnderlyingType> constexpr _UnderlyingType imag(const complex<_UnderlyingType> &)
{
}

// Mathematical Functions
template <typename _UnderlyingType> _UnderlyingType abs(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> _UnderlyingType arg(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> constexpr _UnderlyingType norm(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> constexpr complex<_UnderlyingType> conj(const complex<_UnderlyingType> &)
{
}
template <class _UnderlyingType> complex<_UnderlyingType> proj(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> polar(const _UnderlyingType &, const _UnderlyingType &)
{
}

// Transcendentals
template <typename _UnderlyingType> complex<_UnderlyingType> cos(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> cosh(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> acos(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> acosh(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> sin(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> sinh(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> asin(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> asinh(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> tan(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> tanh(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> atan(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> atanh(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> exp(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> log(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> log10(const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType, typename _ExponentialType>
complex<_UnderlyingType> pow(const complex<_UnderlyingType> &, const _ExponentialType &)
{
}
template <typename _UnderlyingType, typename _BaseType>
complex<_UnderlyingType> pow(const _BaseType &, const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType>
complex<_UnderlyingType> pow(const complex<_UnderlyingType> &, const complex<_UnderlyingType> &)
{
}
template <typename _UnderlyingType> complex<_UnderlyingType> sqrt(const complex<_UnderlyingType> &)
{
}

} // namespace hypercomplex
#endif // COMPLEX_HPP

// footer-begin ------------------------------------------
// default.C++
// File       : complex.hpp
// footer-end --------------------------------------------