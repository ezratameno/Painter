#pragma once
#include "Figure.h"
#include"framework.h"
class Triangle :
	public Figure
{
	DECLARE_SERIAL(Triangle)

private:
	CPoint p3;
public:
	Triangle(const CPoint& p1, const CPoint& p2);
	virtual void redefine(const CPoint& p1, const CPoint& p2);
	virtual void draw(CDC* dc)const;
	virtual bool isInside(const CPoint &P)const;
	float area(int x1, int y1, int x2, int y2, int x3, int y3)const;
	virtual void Serialize(CArchive& ar);
	virtual void Shift(int dx, int dy);
	Triangle() {}
	void set_p3_x(LONG h);
	void set_p3_y(LONG h);
	LONG get_p3_x();
	LONG get_p3_y();
	CPoint get_p3()const;
	void set_p3(CPoint &p);
};

