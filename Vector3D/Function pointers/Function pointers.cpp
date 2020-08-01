// Function pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
	int(*function_pointer)(const int&, const int&);

	function_pointer = &add;

	std::cout << (*function_pointer)(1, 3) << std::endl;

	function_pointer = &multiply;

	std::cout << (*function_pointer)(1, 3) << std::endl;

	return 0;
}

