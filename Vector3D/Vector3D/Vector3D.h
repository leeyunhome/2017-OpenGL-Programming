#pragma once

template<typename TT>
class Vector3D
{
public:
	TT x_, y_, z_;

	Vector3D()
		: x_(0.0), y_(0.0), z_(0.0)
	{}

	Vector3D(const TT& _x, const TT& _y, const TT& _z)
		: x_(_x), y_(_y), z_(_z)
	{}

	void assign(const TT& _x, const TT& _y, const TT& _z)
	{
		x_ = _x;
		y_ = _y;
		z_ = _z;
	}

	void print()
	{
		std::cout << x_ << " " << y_ << " " << z_ << std::endl;
	}
};

template<class TT>
static Vector3D<TT> crossProduct(const Vector3D<TT>& v1, const Vector3D<TT>& v2)
{
	return Vector3D<TT>(v1.y_ * v2.z_ - v1.z_ * v2.y_, v1.z_ * v2.x_ - v1.x_ * v2.z_, v1.x_ * v2.y_ - v1.y_ * v2.x_);
}

/*
float dotProduct(cont Vector2D& v0, const Vector2D& v1)
*/