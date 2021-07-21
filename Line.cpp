#include "pch.h"
#include "Line.h"
IMPLEMENT_SERIAL(Line, CObject, 1)

void Line::draw(CDC * dc) const
{
	CBrush myb(this->brush_color);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(&myb);
	dc->SelectObject(&myp);
	CPoint arr[2] = { p1,p2 };
	dc->Polygon(arr, 2);
}

void Line::redefine(const CPoint & p1, const CPoint & p2)
{
	this->p1 = p1;
	this->p2 = p2;
}

bool Line::isInside(const CPoint & P) const
{
	if (abs(distance(P, p1)) <= 5 || abs(distance(P, p2)) <= 5)//נותן רדיוס של 5 ביטחון
		return true;
	return false;
}

Line::Line(const CPoint & p1, const CPoint & p2):Figure(p1,p2)
{
}

double Line::distance(const CPoint & p1, const CPoint & p2) const
{
	return(sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y)));
}


