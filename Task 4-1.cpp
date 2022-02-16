#include <iostream>
#include <random>

/**
*   \brief Считывает размер массива.
*   \param message Сообщение пользователю.
*   \return Размер массива.
*/
size_t getSize(const std::string& message = "");

/**
*   \brief Считывает значения элементов массива с клавиатуры.
*   \param size Длина массива.
*   \return Массив.
*/
int* getManualInputArray(const size_t size);

/**
*   \brief Заполнение массива случайными числами.
*   \param size Длина массива.
*	\param minValue Минимальное значение массива.
*	\param maxValue Максимальное значение массива.
*   \return Массив.
*/
int* getRandomInputArray(const size_t size, const int minValue = -1000, const int maxValue = 1000);

/**
*   \brief Печатает массив.
*   \param array Массив.
*   \param size Длина массива.
*   \param out Поток вывода.
*/
void print(int* array, const size_t size, std::ostream& out = std::cout);

/**
*   \brief Находит сумму всех чётных элементов.
*   \param array Массив.
*   \param size Длина массива.
*/
int findSummOfAllEvenElements(int* array, const size_t size);

/**
*   \brief Находит элементы массива, значения которых состоят из двух чисел.
*   \param array Массив.
*   \param size Длина массива.
*/
int countAllTwoDigits(int* array, const size_t size);

/**
*   \brief Находит и заменяет последнее отрицательный элемент массива на модуль первого элемента.
*   \param array Массив.
*   \param size Длина массива.
*/
void exchangeLastNegativeElementByAbsOfFirst(int* array, const size_t size);

/**
*   \breif Класс для выбора заполнения массива.
*   \param MANUAL Ручной способ.
*   \param RANDOM Заполнение массива случайными числами.
*/
enum class arrayInputChoice
{
	MANUAL,
	RANDOM
};

/**
*   \brief Точка входа в программу.
*   \return 0 в случае успеха.
*/
int main()
{
	try{
		const auto size = getSize("Введите размер массива = ");
		int* myArray = nullptr;

		std::cout << "Введите требуемое действие \n" << static_cast<int>(arrayInputChoice::MANUAL) << " для ручного ввода массива\n"
			<< static_cast<int>(arrayInputChoice::RANDOM) << " для заполнения массива случайными числами\n";
		int userInput = 0;
		std::cin >> userInput;
		const auto choice = static_cast<arrayInputChoice>(userInput);

		switch (choice)
		{
		case arrayInputChoice::MANUAL:
		{
			myArray = getManualInputArray(size);
			break;
		}
		case arrayInputChoice::RANDOM:
		{
			myArray = getRandomInputArray(size);
			break;
		}
		default:
			std::cerr << "Вы ввели некорректное действие!";
			return 1;
		}

		print(myArray, size);
		
		const int summ = findSummOfAllEvenElements(myArray, size);
		std::cout << "Сумма всех чётных элементов массива = " << summ << "\n";

		const int count = countAllTwoDigits(myArray, size);
		std::cout << "Количество всех элементов с двухзначными числами = " << count << "\n";

		exchangeLastNegativeElementByAbsOfFirst(myArray, size);
		std::cout << "Заменим последнее отрицательное число на модуль первого элемента массива.\n";
		print(myArray, size);

		if (myArray != nullptr)
		{
			delete[] myArray;
			myArray = nullptr;
		}

		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
}

size_t getSize(const std::string& message)
{
	const auto TRESHOLD = 1;
	int size = TRESHOLD;
	std::cout << message;
	std::cin >> size;

	if (size < TRESHOLD)
	{
		throw std::out_of_range("Введён неправильный размер массива!");
	}

	return size;
}

int* getManualInputArray(const size_t size)
{	
	int* myArray = new int[size];
	
	std::cout << "Введите элементы массива\n";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "A[" << i + 1 << "] = ";
		std::cin >> myArray[i];
	}

	return myArray;
}

int* getRandomInputArray(const size_t size, const int minValue, const int maxValue)
{
	std::random_device random;
	std::mt19937 gen(random());
	const std::uniform_int_distribution<int> uniformDistributation(minValue, maxValue);

	int* myArray = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		myArray[i] = uniformDistributation(gen);
	}

	return myArray;
}

void print(int* array, const size_t size, std::ostream& out)
{
	out << "Массив:\n";
	for (size_t i = 0; i < size; i++)
	{
		out << array[i] << " ";
	}
	out << "\n";
}

int findSummOfAllEvenElements(int* array, const size_t size)
{
	int summ = 0;
	for (size_t i = 0; i <= size; i++)
	{
		if (array[i] % 2 == 0)
		{
			summ = summ + array[i];
		}
	}
	return summ;
}

int countAllTwoDigits(int* array, const size_t size)
{
	int count = 0;
	for (size_t i = 0; i <= size; i++)
	{
		if ((array[i] >= -99 && array[i] <= -10) || (array[i] >= 10 && array[i] <= 99))
		{
			count++; 
		}
	}
	return count;
}

void exchangeLastNegativeElementByAbsOfFirst(int* array, const size_t size)
{
	size_t i = 0;
	auto negativeNumber = 0;
	while (i < size)
	{ 
		if (array[i] < 0)
		{
			negativeNumber = i;
		}
		i++;
	}
	array[negativeNumber] = abs(array[0]);
}

