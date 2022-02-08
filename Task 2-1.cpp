#include <iostream>

/**
*	\brief Вычисляет сумму чисел.
*	\param a Первое число.
*	\param b Второе число.
*	\return Сумма чисел.
*/
double getSumm(double number1, double number2);

/**
*	\brief Вычисляет разность чисел.
*	\param a Первое число.
*	\param b Второе число.
*	\return Разность чисел.
*/
double getDifference(double number1, double number2);

/**
*	\brief Вычисляет произведение чисел.
*	\param a Первое число.
*	\param b Второе число.
*	\return Произведение чисел.
*/
double getMultiplication(double number1, double number2);

/**
*	\brief Вычисляет частное от чисел.
*	\param a Первое число.
*	\param b Второе число.
*	\return Частное от чисел.
*/
double getQuotient(double number1, double number2);

/**
*	\brief Пользовательский ввод
*	\param SUMM Вычисление суммы чисел
*	\param DIFFERENCE Вычисление разности чисел
*	\param MULTIPLICATION Вычисление произведения чисел
*	\param QUOTIENT Вычисление частного от чисел
*/
enum class userInput
{
	SUMM = 1,
	DIFFERENCE,
	MULTIPLICATION,
	QUOTIENT
};

/**
*	\brief Точка входа в программу.
*	\return Возращает 0 в случае успеха.
*/
int main()
{
	std::cout << "Введите первое число = ";
	double number1 = 0.0;
	std::cin >> number1;
	std::cout << "Введите второе число = ";
	double number2 = 0.0;
	std::cin >> number2;

	std::cout << "Введите число, соответствующее заданию.\n"
		<< static_cast<int>(userInput::SUMM) << " - вычисление суммы чисел; "
		<< static_cast<int>(userInput::DIFFERENCE) << " - вычисление разности чисел; "
		<< static_cast<int>(userInput::MULTIPLICATION) << " - вычисление произведения чисел; "
		<< static_cast<int>(userInput::QUOTIENT) << " - вычисление частного от чисел.\n";

	int input = 0;
	std::cin >> input;
	const auto choise = static_cast<userInput>(input);

	switch (choise)
	{
	case userInput::SUMM:
		{
			const auto summ = getSumm(number1, number2);
			std::cout << "Сумма = " << summ;
			break;
		}
	case userInput::DIFFERENCE:
		{
			const auto difference = getDifference(number1, number2);
			std::cout << "Разность = " << difference;
			break;
		}
	case userInput::MULTIPLICATION:
		{
			const auto multiplication = getMultiplication(number1, number2);
			std::cout << "Произведение = " << multiplication;
			break;
		}
	case userInput::QUOTIENT:
		{
			if (number2 != 0)
			{
				const auto quotient = getQuotient(number1, number2);
				std::cout << "Частное = " << quotient;
				break;
			}
			else std::cout << "Неверные данные";
		}
		
	}

	return 0;
}

double getSumm(const double number1, const double number2)
{
	return number1 + number2;
}

double getDifference(const double number1, const double number2)
{
	return number1 - number2;
}

double getMultiplication(const double number1, const double number2)
{
	return number1 * number2;
}

double getQuotient(const double number1, const double number2)
{
	return number1 / number2;
}