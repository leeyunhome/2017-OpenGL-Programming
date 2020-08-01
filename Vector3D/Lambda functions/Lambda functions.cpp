// Lambda functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int worker(const int& a, const int& b, int(*func_ptr)(const int&, const int&))
{
	return (*func_ptr)(a, b);
}
int main()
{
	//std::cout << 
	//[](const int& a, const int& b)->int
	//{
	//	return a + b;
	//}
	//(1, 3)
	//<< std::endl;

	std::cout << 
		worker(1, 3, [](const int& a, const int& b)->int
			{
				return a + b;
			})
	<< std::endl;

	std::cout <<
		worker(1, 3, [](const int& a, const int& b)->int
			{
				return a * b;
			})
	<< std::endl;

	return 0;
}

