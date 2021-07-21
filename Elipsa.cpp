#include "pch.h"
#include "elipsa.h"
IMPLEMENT_SERIAL(Elipsa, CObject, 1)

void Elipsa::draw(CDC * dc) const
{
	CBrush myb(this->brush_color);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(&myb);
	dc->SelectObject(&myp);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}

void Elipsa::change_pen_color_and_size(COLORREF p, int t)
{
	this->pen_color = p;
	pen_size = t;
}

Elipsa::Elipsa(const CPoint& p1, const CPoint& p2):Rectangle_my(p1, p2)
{
}

bool Elipsa::isInside(const CPoint & s)const
{
	double x = (p1.x + p2.x) / 2;
	double y = (p1.y + p2.y) / 2;
	double b = y - p1.y;
	double a = x - p1.x;
	double res = pow((s.x - x), 2) / pow(a, 2) + pow((s.y - y), 2) / pow(b, 2);
	return(res <= 1);
}





