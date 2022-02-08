#include <iostream>
#include <iomanip>

/**
*   \brief Существует ли функция в точке х.
*   \param x Аргумент функции
*   \return true, если существует.
*/
bool isExists(const double x);

/**
*   \brief Расчёт функции в точке х.
*   \param x Аргумент функции
*   \return Значение функции в точке х.
*/
double getY(const double x);

/**
*   \brief Точка входа в программу.
*   \return 0 в случае успеха.
*/
int main()
{
    const double xStart = 1;
    const double xFinish = 3;
    const double step = 0.2;
    double x = xStart;

    std::cout << std::setw(10) <<  " x " << "  "<< " y "<<"\n";

    while (x <= xFinish + step)
    {
        if (isExists(x))
        {
            const double y = getY(x);
            //std::cout << "x: " << x << " y: " << y << "\n";
            std::cout << std::setw(10) << x << "  " << y << "\n";
        }
        else
        {
            std::cout << std::setw(10) << x << " " << "Нет решения" << "\n";
        }

        x += step;
    }
    return 0;
}

bool isExists(const double x)
{
    return  x > 0;
}

double getY(const double x)
{
    return std::sin(std::log(x)) - std::cos(std::log(x)) + 2 * std::log(x);
}

