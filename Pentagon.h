#pragma once
#include "Figure.h"
#include"Triangle.h"
class Pentagon :
	public Figure
{
	DECLARE_SERIAL(Pentagon)
private:
	CPoint p3, p4, p5, p6, p7, p8;
	Triangle t1, t2, t3;
public:
	virtual void Serialize(CArchive& ar);
	Pentagon(const CPoint& p1, const CPoint& p2);
	virtual void draw(CDC *dc)const;
	virtual void redefine(const CPoint& p1, const CPoint& p2);
	virtual bool isInside(const CPoint &P)const;
	Pentagon(){}
};

