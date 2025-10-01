#include<iostream>
#include<exception>
#include <limits>
using std::cin;
using std::cout;
using std::endl;

unsigned long long Factorial(int N)
{
	if (N < 0)
	{
		throw std::invalid_argument("Число должно быть положительным!");
	}
	if (N == 0 || N == 1)
	{
		return 1;
	}
	else
	{
		unsigned long long  FactorialPrev = Factorial(N - 1);
		if (FactorialPrev > std::numeric_limits<unsigned long long> ::max() / N)
		{
			throw std::overflow_error("Переполнение!");
		}
		return N * FactorialPrev;
		
	}

}
int main()
{
	system("chcp 1251 > NUL");
	int number = 0;
	try
	{
		cout << "Введите число для вычисления факториала: ";
		cin >> number;
		cout << "Факториал числа: " << number << " составляет " << Factorial(number) << endl;
	}
	catch (const std::invalid_argument& e)
	{
		cout << "Произошла ошибка: " << e.what() << endl;
	}
	catch (const std::overflow_error& e)
	{
		cout << "Произошла ошибка: " << e.what() << endl;
	}
	return 0;
}