#pragma once
#include "Figure.h"
#include"Rectangle_my.h"
#include"Triangle.h"
class Arrow :
	public Figure
{
	DECLARE_SERIAL(Arrow)

private:
	CPoint p3, p4, p5, p6, p7, p8,p9;
	Rectangle_my rec;
	Triangle t;
public:
	virtual void Serialize(CArchive& ar);
	Arrow(const CPoint& p1, const CPoint& p2);
	virtual void draw(CDC *dc)const;
	virtual void redefine(const CPoint& p1, const CPoint& p2);
    virtual bool isInside(const CPoint &P)const;
	Arrow(){}
};

