// Passing Function Pointer as a Parameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int add(const int& a, const int& b)
{
	return a + b;
}

int multiply(const int& a, const int& b)
{
	return a * b;
}

int worker(const int& a, const int& b, int(*func_ptr)(const int&, const int&))
{
	return (*func_ptr)(a, b);
}

int main()
{
	std::cout << worker(1, 3, &add) << std::endl;
	std::cout << worker(1, 3, &multiply) << std::endl;

	return 0;
}

