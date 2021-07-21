#pragma once
#include "Rectangle_my.h"
class Squre :
	public Rectangle_my
{
	DECLARE_SERIAL(Squre)
private:
	CPoint p3, p4;
	LONG side;
public:
	Squre() {}
	Squre(const CPoint& p1, const CPoint& p2);
	virtual void draw(CDC *dc)const;
	virtual void redefine(const CPoint& p1, const CPoint& p2);
	virtual bool isInside(const CPoint &s)const;
	virtual void Serialize(CArchive& ar);
	Squre& operator = (const Squre & other);

};

