// Vector3D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3D.h"

int main()
{
    std::cout << "Hello World!\n";

    // 1. extend Vector2D to Vector3D
    // 2. implement crossproduct between two vector.
    // Hint: You google sample code.

    Vector3D<float> v0(1, 0, 0), v1(0, 1, 0);

    Vector3D<float> cr = crossProduct(v0, v1);

    cr.print();

    return 0;
}

