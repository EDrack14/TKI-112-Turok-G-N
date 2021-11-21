#include <iostream>

int main()
{
    float x, y,sum,dif,prod,quo;
    std::cin >>x>>y; //Ввод переменных с клавиатуры
    std::cout <<"x:"<< x << " y:" << y << std::endl;
    sum = x + y; dif = x - y; prod = x * y; quo = x / y;
    std::cout <<"sum:"<< sum << " dif:" << dif << " prod:" << prod << " quo:" << quo;
}

