// header-begin ------------------------------------------
// File       : main.cpp
//
// Author      : Joshua E
// Email       : estesjn2020@gmail.com
//
// Created on  : 8/3/2025
//
// header-end --------------------------------------------

#include <cmath>
#include <iostream>
#include <complex>
#include "hypercomplex/complex.hpp"

int main()
{
    std::complex<double> c1(4.5f, 3.98f);
    std::complex<double> c2(2.81f, 2.33f);

    hypercomplex::complex<double> hc1(4.5f, 3.98f);
    hypercomplex::complex<double> hc2(2.81f, 2.33f);

    std::cout << c1 << std::endl;
    c1 *= c2;
    std::cout << c1 << std::endl;

    std::cout << hc1 << std::endl;
    hc1 *= hc2;
    std::cout << hc1 << std::endl;
}

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------