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
	float rho = std::numeric_limits<float>::infinity();
	float theta = 5;
	std::cout << hypercomplex::polar(rho, theta) << "\n";
	std::cout << std::polar(rho, theta) << "\n";
}

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------