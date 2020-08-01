#pragma once

template<class TT>
class Matrix2X2
{
public:
	TT v00_, v01_;
	TT v10_, v11_;

	Matrix2X2(const TT& _v00, const TT& _v01, const TT& _v10, const TT& _v11)
		: v00_(_v00), v01_(_v01), v10_(_v10), v11_(_v11)
	{}

	Vector
};

