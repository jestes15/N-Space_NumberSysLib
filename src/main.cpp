// header-begin ------------------------------------------
// File       : main.cpp
//
// Author      : Joshua E
// Email       : estesjn2020@gmail.com
//
// Created on  : 8/4/2025
//
// header-end --------------------------------------------

// header-begin ------------------------------------------
// File       : main.cpp
//
// Author      : Joshua E
// Email       : estesjn2020@gmail.com
//
// Created on  : 8/3/2025
//
// header-end --------------------------------------------

#include "hypercomplex/complex.hpp"
#include <complex>
#include <iostream>

int
main()
{
  hypercomplex::complex<float> c(1.0f, 2.0f);
  c *= 2.0f;

  std::complex<float> o(1.0f, 2.0f);
  o *= 2.0f;

  std::cout << c << "\n";
  std::cout << o << "\n";
}

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------