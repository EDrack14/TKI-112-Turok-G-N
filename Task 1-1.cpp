#include <iostream>
#include <cmath> 

/**
* \brief Функция рассчёта по заданной формуле
* \param a Первый параметр функции
*/
void ExampleA(double a)
{
    //double a;
    a = (exp(-y * z) * sin(x * z - y) - sqrt(abs(y * z + x)));
}

/**
* \brief Функция рассчёта по заданной формуле
* \param b Первый параметр функции
*/
void ExampleB()
{
    double b;
    b = (y * sin(a * pow(z, 2) * cos(2 * z)) - 1);
}

int main()
{ 
    const double x = -0.5, y = 1.7, z = 0.44; 
    std::cout << "x:"<<x<<"; y:"<<y<<"; z:"<<z<<std::endl; 
    ExampleA();
    ExampleB();
    std::cout << "a:"<<a<<"; b:"<<b;
}

