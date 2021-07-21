#pragma once
#include "Figure.h"
class Line :
	public Figure
{
	DECLARE_SERIAL(Line)

public:
	virtual void draw(CDC *dc)const;
	virtual void redefine(const CPoint& p1, const CPoint& p2);
	virtual bool isInside(const CPoint &P)const;
	Line(const CPoint& p1, const CPoint& p2);
	double distance(const CPoint& p1,const CPoint& p2)const;

	Line() {}

};

