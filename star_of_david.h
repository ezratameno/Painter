#pragma once
#include "Figure.h"
#include"Triangle.h"
class star_of_david :
	public Figure
{
	DECLARE_SERIAL(star_of_david)
private:
	Triangle t1, t2;
	CPoint p3, p4, p5, p6, p7, p8, p9, p10, p11,p12,p13,p14;
public:
	virtual void draw(CDC *dc)const;
	virtual void redefine(const CPoint& p1, const CPoint& p2);
	virtual bool isInside(const CPoint &P)const;
	star_of_david(){}
	star_of_david(const CPoint& p1, const CPoint& p2);
	virtual void Serialize(CArchive& ar);

};

