#pragma once
#include "Figure.h"
class Rectangle_my :
	public Figure
{
	DECLARE_SERIAL(Rectangle_my)
public:
	Rectangle_my(const CPoint& p1, const CPoint& p2);
	Rectangle_my() {}
};

