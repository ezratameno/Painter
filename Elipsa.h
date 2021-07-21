#pragma once
#include"Rectangle_my.h"
class Elipsa :
	public Rectangle_my
{
	DECLARE_SERIAL(Elipsa)
public:
	void draw(CDC *dc)const;
	virtual void change_pen_color_and_size(COLORREF p, int t);
	Elipsa(const CPoint& p1, const CPoint& p2);
	virtual bool isInside(const CPoint &s) const;
	Elipsa()
	{
	}
};

