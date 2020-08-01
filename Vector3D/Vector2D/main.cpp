// Vector2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3D.h"

template<class TT>
class Vector2D
{
public:
	TT x_, y_;

	Vector2D()
		: x_(TT()), y_(TT())
	{}

	Vector2D(const TT& _x, const TT& _y)
		: x_(_x), y_(_y)
	{}

	TT getMagnitude()
	{
		return sqrt(x_ * x_ + y_ * y_);
	}

	// over-loading for speedup
	void getMagnitude(TT& mag)
	{
		mag = sqrt(x_ * x_ + y_ * y_);
	}

	void normalize()
	{
		const TT mag;
		mag = getMagnitude();
		x_ / mag;
		y_ / mag;
	}
	Vector2D<TT> getNormalized()
	{
		const TT magnitude = getMagnitude();
		return Vector2D(x_ / magnitude, y_ / magnitude);
	}
	// over-riding stream operator
	friend std::ostream& operator << (std::ostream& out, const Vector2D& vec)
	{
		out << "(" << vec.x_ << ", " << vec.y_ << ")";
		return out;
	}
};

template<class TT>
class Matrix2X2
{
public:
	TT v00_, v01_;
	TT v10_, v11_;

	Matrix2X2(const TT& _v00, const TT& _v01, const TT& _v10, const TT& _v11)
		: v00_(_v00), v01_(_v01), v10_(_v10), v11_(_v11)
	{}

	/*Vector2D<TT> multiplyWith(const Matrix2X2& mat, const Vector2D& vec)
	{
		return Vector2D(mat.v00_ * vec.x_ + mat.v01_ * vec.y_, mat.v10_ * vec.x_ + mat.v11_ * vec.y_);
	}*/
	Vector2D<TT> multiplyWith(const Vector2D<TT>& vec)
	{
		Vector2D<TT> vec_ans;
		vec_ans.x_ = v00_ * vec.x_ + v01_ * vec.y_;
		vec_ans.y_ = v10_ * vec.x_ + v11_ * vec.y_;
		return vec_ans;
	}
};

template<class TT> TT dotProduct(const Vector2D<TT>& v0, const Vector2D<TT>& v1)
{
	return v0.x_ * v1.x_ + v0.y_ * v1.y_;
}


int main()
{
	//Vector2D<float> my_float_vec(1.12f, 2.34f);
	//Vector2D<double> my_double_vec(3.56, 4.78);
	//Vector2D<int> my_int_vec(1.245f, 3.1231f);

	//std::cout << my_float_vec << std::endl;
	//std::cout << my_double_vec << std::endl;
	//std::cout << my_int_vec << std::endl;

	/*Vector2D<float> car_velocity(4.0f, 3.0f);

	std::cout << "Velocity of a car is " << car_velocity << std::endl;
	std::cout << "Speed of this car is " << car_velocity.getMagnitude() << std::endl;
	std::cout << "Direction of this car's velocity is " << car_velocity.getNormalized() << std::endl;*/

	/*Vector3D<float> my_vector_1, my_vector_2;
	my_vector_1.x_ = 1.0f;
	my_vector_1.y_ = 0.0f;
	my_vector_1.z_ = 0.0f;

	my_vector_2.x_ = 0.0f;
	my_vector_2.y_ = 1.0f;
	my_vector_2.z_ = 0.0f;

	Vector3D<float> cross_v1_v2 = crossProduct(my_vector_1, my_vector_2);

	for (int d = 0; d < 3; d++)
		std::cout << cross_v1_v2.values_[d] << std::endl;*/
	Matrix2X2<float> matrix(1, 0, 0, 1);
	Vector2D<float> vector(1, 2);
	Vector2D<float> ans = matrix.multiplyWith(vector);

	std::cout << __LINE__ << " " << ans << std::endl;

	return 0;
}
