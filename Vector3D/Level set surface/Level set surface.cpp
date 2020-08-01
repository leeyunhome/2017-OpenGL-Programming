// Level set surface.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SQR(a) (a)*(a)
#define ABS(a) ((a) > 0? (a) : -(a))

#include <iostream>
#include <math.h>

class ImplicitCircle2D
{
public:
	float x_center_, y_center_;
	float radius_;

	float getValue(const float& x, const float& y)
	{
		return SQR(x - x_center_) + SQR(y - y_center_) - SQR(radius_);
	}

	float getSignedDistance(const float& x, const float& y)
	{
		return sqrt(SQR(x - x_center_) + SQR(y - y_center_)) - radius_;
	}
};

int main()
{
	ImplicitCircle2D my_circle;
	my_circle.x_center_ = 0.0f;
	my_circle.y_center_ = 0.0f;
	my_circle.radius_ = 1.0f;

	std::cout << my_circle.getSignedDistance(0.0f, 0.0f) << std::endl;
	std::cout << my_circle.getSignedDistance(1.0f, 0.0f) << std::endl;
	std::cout << my_circle.getSignedDistance(2.0f, 0.0f) << std::endl;

	return 0;
}

