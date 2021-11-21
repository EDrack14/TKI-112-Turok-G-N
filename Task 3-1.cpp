#include <iostream>
#include <cmath>

int main()
{
	float dx,y,x;
	dx = 0.2;
	x = 1;
	for (x; x <= 3.1; x=x+dx) //Цикл for будет решать функцию и выводить результаты пока x не превысит 3.1, после каждого решения к x прибавляется значение dx
	{
		y = sin(log(x)) - cos(log(x)) + 2 * log(x);
		std::cout << "y = "<<y<<" when x = " << x << std::endl;
	}
}