// Polymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class GeometricObject
{
public:
	virtual void test()
	{
		std::cout << "I am GeometricObject" << std::endl;
	}
};

class Triangle : public GeometricObject
{
public:
	void test()
	{
		std::cout << "I am Triangle" << std::endl;
	}
};

class Circle : public GeometricObject
{
public:
	void test()
	{
		std::cout << "I am Circle" << std::endl;
	}
};

int main()
{
	//GeometricObject geo_obj;
	//
	//geo_obj.test();

	/*GeometricObject* geo_obj = new GeometricObject;
	Triangle* my_triangle = new Triangle;
	Circle* my_circle = new Circle;

	geo_obj->test();
	my_triangle->test();
	my_circle->test();

	delete geo_obj;
	delete my_triangle;
	delete my_circle;*/
	GeometricObject* geo_obj1 = new Triangle;
	GeometricObject* geo_obj2 = new Circle;

	geo_obj1->test();
	geo_obj2->test();

	delete geo_obj1;
	delete geo_obj2;

	return 0;
}

