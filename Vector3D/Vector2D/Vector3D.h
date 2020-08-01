#pragma once

#include <iostream>

template<class TT>
class Vector3D
{
public:
	union
	{
		struct { TT x_, y_, z_; };
		struct { TT v0_, v1_, v2_; };
		TT values_[3];
	};

	Vector3D()
		: x_(TT()), y_(TT()), z_(TT())
	{}

	Vector3D(const TT& _x, const TT& _y, const TT& _z)
		: x_(_x), y_(_y), z_(_z)
	{}
};

template<class TT> Vector3D<TT> crossProduct(const Vector3D<TT>& v0, const Vector3D<TT>& v1)
{
	return Vector3D<TT>(v0.y_ * v1.z_ - v0.z_ * v1.y_, v0.z_ * v1.x_ - v0.x_ * v1.z_, v0.x_ * v1.y_ - v0.y_ * v1.x_);
}