#define _Use_Math_Defines
#include <iostream>
#include <cmath>

/**
*	\brief Функция расчёта по заданной формуле.
*	\param х Аргумент функции.
*	\param y Аргумент функции.
*	\param z Аргумент функции.
*	\return Значение функции.
*/
double getA(double x, double y, double z);

/**
*	\brief Функция расчёта по заданной формуле.
	\param a Аргумент функции.	
	\param y Аргумент функции.
*	\param z Аргумент функции.
*	\return Значение функции.
*/
double getB(double a, double y, double z);

/**
*	\brief Точка входа в программу.
*	\return Возвращает 0 в случае успеха.
*/
int main()
{
	const double x = -0.5;
	const double y = 1.7;
	const double z = 0.44;
	const double a = getA(x, y, z);
	const double b = getB(a, y, z);
	std::cout << "x = " << x << " y = " << y << " z = " << z << "\n";
	std::cout << "a = " << a << " b = " << b << std::endl;
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return exp(-y * z) * sin(x * z - y) - sqrt(abs(y * z + x));
}

double getB(const double a, const double y, const double z)
{
	return y * sin(a * pow(z, 2) * cos(2 * z)) - 1;
}

