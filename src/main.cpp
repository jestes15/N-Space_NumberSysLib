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
  hypercomplex::complex<float> dut(1.0f, 2.0f);
  std::complex<float> ref(1.0f, 2.0f);

  std::cout << hypercomplex::cot(dut) << "\n";
  std::cout << 1.0f / std::tan(ref) << "\n";
}

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------