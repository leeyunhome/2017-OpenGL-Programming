// Implicit Surface.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SQR(a) (a)*(a)
#include <iostream>

class Vector2D
{
public:
    float x_, y_;
};

class ImplicitCircle2D
{
public:
    float x_center_, y_center_;
    float radius_;

    float getValue(const float& x, const float& y)
    {
        return SQR(x - x_center_) + SQR(y - y_center_) - SQR(radius_);
    }
};
int main()
{
    ImplicitCircle2D my_circle;
    my_circle.x_center_ = 0.0f;
    my_circle.y_center_ = 0.0f;
    my_circle.radius_ = 1.0f;

    std::cout << my_circle.getValue(0.0f, 0.0f) << std::endl;
    std::cout << my_circle.getValue(1.0f, 0.0f) << std::endl;
    std::cout << my_circle.getValue(2.0f, 0.0f) << std::endl;

    return 0;
}
