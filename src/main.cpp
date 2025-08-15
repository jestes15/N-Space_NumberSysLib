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
#include <cmath>
#include <complex>
#include <cuda/std/complex>
#include <iostream>
#include <limits>

int
main()
{
	double inf = std::numeric_limits<double>::infinity();
	double nan = std::numeric_limits<double>::quiet_NaN();
	double pi = std::acos(-1.0);

	std::cout << "Standard Library" << std::endl;
	// Test cases for r = 0
	std::cout << "r: 0, theta: 0: " << std::polar(0.0, 0.0) << std::endl;
	std::cout << "r: 0, theta: inf: " << std::polar(0.0, inf) << std::endl;
	std::cout << "r: 0, theta: nan: " << std::polar(0.0, nan) << std::endl;
	std::cout << "r: 0, theta: -1: " << std::polar(0.0, -1.0) << std::endl;
	std::cout << "r: 0, theta: 1: " << std::polar(0.0, 1.0) << std::endl;

	// Test cases for r = R (using R = 1 as a representative real number)
	std::cout << "r: 1, theta: 0: " << std::polar(1.0, 0.0) << std::endl;
	std::cout << "r: 1, theta: inf: " << std::polar(1.0, inf) << std::endl;
	std::cout << "r: 1, theta: nan: " << std::polar(1.0, nan) << std::endl;
	std::cout << "r: 1, theta: -1: " << std::polar(1.0, -1.0) << std::endl;
	std::cout << "r: 1, theta: 1: " << std::polar(1.0, 1.0) << std::endl;

	// Test cases for r = -R (using R = 1)
	std::cout << "r: -1, theta: 0: " << std::polar(-1.0, 0.0) << std::endl;
	std::cout << "r: -1, theta: inf: " << std::polar(-1.0, inf) << std::endl;
	std::cout << "r: -1, theta: nan: " << std::polar(-1.0, nan) << std::endl;
	std::cout << "r: -1, theta: -1: " << std::polar(-1.0, -1.0) << std::endl;
	std::cout << "r: -1, theta: 1: " << std::polar(-1.0, 1.0) << std::endl;

	// Test cases for r = inf
	std::cout << "r: inf, theta: 0: " << std::polar(inf, 0.0) << std::endl;
	std::cout << "r: inf, theta: inf: " << std::polar(inf, inf) << std::endl;
	std::cout << "r: inf, theta: nan: " << std::polar(inf, nan) << std::endl;
	std::cout << "r: inf, theta: -1: " << std::polar(inf, -1.0) << std::endl;
	std::cout << "r: inf, theta: 1: " << std::polar(inf, 1.0) << std::endl;

	// Test cases for r = nan
	std::cout << "r: nan, theta: 0: " << std::polar(nan, 0.0) << std::endl;
	std::cout << "r: nan, theta: inf: " << std::polar(nan, inf) << std::endl;
	std::cout << "r: nan, theta: nan: " << std::polar(nan, nan) << std::endl;
	std::cout << "r: nan, theta: -1: " << std::polar(nan, -1.0) << std::endl;
	std::cout << "r: nan, theta: -1: " << std::polar(nan, 1.0) << std::endl;

	std::cout << "CUDA Standard Library" << std::endl;
	// Test cases for r = 0
	std::cout << "r: 0, theta: 0: " << cuda::std::polar(0.0, 0.0) << std::endl;
	std::cout << "r: 0, theta: inf: " << cuda::std::polar(0.0, inf) << std::endl;
	std::cout << "r: 0, theta: nan: " << cuda::std::polar(0.0, nan) << std::endl;
	std::cout << "r: 0, theta: -1: " << cuda::std::polar(0.0, -1.0) << std::endl;
	std::cout << "r: 0, theta: 1: " << cuda::std::polar(0.0, 1.0) << std::endl;

	// Test cases for r = R (using R = 1 as a representative real number)
	std::cout << "r: 1, theta: 0: " << cuda::std::polar(1.0, 0.0) << std::endl;
	std::cout << "r: 1, theta: inf: " << cuda::std::polar(1.0, inf) << std::endl;
	std::cout << "r: 1, theta: nan: " << cuda::std::polar(1.0, nan) << std::endl;
	std::cout << "r: 1, theta: -1: " << cuda::std::polar(1.0, -1.0) << std::endl;
	std::cout << "r: 1, theta: 1: " << cuda::std::polar(1.0, 1.0) << std::endl;

	// Test cases for r = -R (using R = 1)
	std::cout << "r: -1, theta: 0: " << cuda::std::polar(-1.0, 0.0) << std::endl;
	std::cout << "r: -1, theta: inf: " << cuda::std::polar(-1.0, inf) << std::endl;
	std::cout << "r: -1, theta: nan: " << cuda::std::polar(-1.0, nan) << std::endl;
	std::cout << "r: -1, theta: -1: " << cuda::std::polar(-1.0, -1.0) << std::endl;
	std::cout << "r: -1, theta: 1: " << cuda::std::polar(-1.0, 1.0) << std::endl;

	// Test cases for r = inf
	std::cout << "r: inf, theta: 0: " << cuda::std::polar(inf, 0.0) << std::endl;
	std::cout << "r: inf, theta: inf: " << cuda::std::polar(inf, inf) << std::endl;
	std::cout << "r: inf, theta: nan: " << cuda::std::polar(inf, nan) << std::endl;
	std::cout << "r: inf, theta: -1: " << cuda::std::polar(inf, -1.0) << std::endl;
	std::cout << "r: inf, theta: 1: " << cuda::std::polar(inf, 1.0) << std::endl;

	// Test cases for r = nan
	std::cout << "r: nan, theta: 0: " << cuda::std::polar(nan, 0.0) << std::endl;
	std::cout << "r: nan, theta: inf: " << cuda::std::polar(nan, inf) << std::endl;
	std::cout << "r: nan, theta: nan: " << cuda::std::polar(nan, nan) << std::endl;
	std::cout << "r: nan, theta: -1: " << cuda::std::polar(nan, -1.0) << std::endl;
	std::cout << "r: nan, theta: -1: " << cuda::std::polar(nan, 1.0) << std::endl;
}

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------