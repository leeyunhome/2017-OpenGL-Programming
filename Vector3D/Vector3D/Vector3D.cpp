// Vector3D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3D.h"
#include "Matrix3X3.h"

int main()
{
    //std::cout << "Hello World!\n";

    //// 1. extend Vector2D to Vector3D
    //// 2. implement crossproduct between two vector.
    //// Hint: You google sample code.

    //Vector3D<float> v0(1, 0, 0), v1(0, 1, 0);

    //Vector3D<float> cr = crossProduct(v0, v1);

    //cr.print();

    Matrix3X3 m;

    unsigned int count = 0;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
        {
            m.value_[row][col] = (float)count++;
        }

    //m.print();
    //m.value_[0][0] = ...;
    //m.value_[0][1] = ...;
    //m.value_[0][2] = ...;

    Vector3D<float> v(0, 1, 2);
    Vector3D<float> result = multiply(m, v);

    m.print();
    v.print();
    result.print();

    return 0;
}

