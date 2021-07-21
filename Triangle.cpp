#include "pch.h"
#include "Triangle.h"

IMPLEMENT_SERIAL(Triangle, CObject, 1)

Triangle::Triangle(const CPoint& p1, const CPoint& p2) : Figure(p1, p2)
{
}

void Triangle::redefine(const CPoint& p1, const CPoint& p2)//p1 - ראש המשולש
		//P2- הבסיס הימנית
		//P3- שמאל
		//אני מקבל את p1 &p2
{
	this->p2 = p2;
	this->p1 = p1;
	p3.x = p1.x;
	this->p1.x = (p1.x + p2.x) / 2;//משתנה
	this->p3.y = p2.y;//משתנה

}


void Triangle::draw(CDC * dc)const
{
	CBrush myb(this->brush_color);
	dc->SelectObject(&myb);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(myp);
	CPoint arr[3] = { p1,p2,p3 };
	dc->Polygon(arr, 3);
}

bool Triangle::isInside(const CPoint &pt)const
{

	float A = area(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
	float A1 = area(pt.x, pt.y, p2.x, p2.y, p3.x, p3.y);
	float A2 = area(p1.x, p1.y, pt.x, pt.y, p3.x, p3.y);
	float A3 = area(p1.x, p1.y, p2.x, p2.y, pt.x, pt.y);
	return (A == A1 + A2 + A3);
}
float Triangle::area(int x1, int y1, int x2, int y2, int x3, int y3)const
{
	return abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void Triangle::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		ar << p1;
		ar << p2;
		ar << brush_color;
		ar << pen_color;
		ar << pen_size;
		ar << p3;

	}
	else // Loading, not storing
	{
		ar >> p1;
		ar >> p2;
		ar >> brush_color;
		ar >> pen_color;
		ar >> pen_size;
		ar >> p3;

	}
}
//
void Triangle::Shift(int dx, int dy)
{
	p3 = p3 + CPoint(dx, dy);
	p2 = p2 + CPoint(dx, dy);
	p1 = p1 + CPoint(dx, dy);
}




void Triangle::set_p3_x(LONG h)
{
	p3.x = h;
}


void Triangle::set_p3_y(LONG h)
{
	p3.y = h;
}


LONG Triangle::get_p3_x()
{
	return p3.x;
}

LONG Triangle::get_p3_y()
{
	return p3.y;
}

CPoint Triangle::get_p3() const
{
	return p3;
}

void Triangle::set_p3(CPoint & p)
{
	p3 = p;
}






