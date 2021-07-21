#pragma once
#include "Figure.h"
#include"Rectangle_my.h"
#include"Triangle.h"
class Star :
	public Figure
{
	DECLARE_SERIAL(Star)
private:
	Triangle t1, t2, t3, t4;
	Rectangle_my rec;
	CPoint p3, p4, p5, p6, p7, p8,p9,p10;

public:
	virtual void Serialize(CArchive& ar);
	Star(const CPoint& p1, const CPoint& p2);
	virtual void draw(CDC *dc)const;
	virtual void redefine(const CPoint& p1, const CPoint& p2);
	virtual bool isInside(const CPoint &P)const;
	Star() {}
};

