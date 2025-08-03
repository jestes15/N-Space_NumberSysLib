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
 
double L1(unsigned m, double x)
{
    return -x + m + 1;
}
 
double L2(unsigned m, double x)
{
    return 0.5 * (x * x - 2 * (m + 2) * x + (m + 1) * (m + 2));
}
 
int main()
{
    // spot-checks
    std::cout << std::assoc_laguerre(1, 10, 0.5) << '=' << L1(10, 0.5) << '\n'
              << std::assoc_laguerre(2, 10, 0.5) << '=' << L2(10, 0.5) << '\n';
}

// footer-begin ------------------------------------------
// default.C++
// File       : main.cpp
// footer-end --------------------------------------------