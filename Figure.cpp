#include "pch.h"
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)
void Figure::Serialize(CArchive& ar) 
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << p1;
		ar << p2;
		ar << brush_color;
		ar << pen_color;
		ar << pen_size;
	}
	else // Loading, not storing
	{
		ar >> p1;
		ar >> p2;
		ar >> brush_color;
		ar >> pen_color;
		ar >> pen_size;
	}
}
Figure::Figure(const CPoint& p1,const CPoint& p2) : p1(p1), p2(p2) {
	brush_color = RGB(255, 255, 255);//ься
	pen_color = RGB(0, 0, 0);
	pen_size = 3;
}

void Figure::change_brush_color(const COLORREF b)
{
	this->brush_color = b;

}

void Figure::change_pen_color_and_size(const COLORREF p, int t)
{
	this->pen_color = p;
	pen_size = t;
}

void Figure::draw(CDC * dc) const
{
	CBrush myb(this->brush_color);
	dc->SelectObject(&myb);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(myp);
	dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}

void Figure::redefine(const CPoint& p1,const CPoint& p2)
{
	this->p1 = p1;
	this->p2 = p2;
}

bool Figure::isInside(const CPoint & P) const
{
	return (p1.x <= P.x && P.x <= p2.x || p1.x >= P.x && P.x >= p2.x) &&
		(p1.y <= P.y && P.y <= p2.y || p1.y >= P.y && P.y >= p2.y);
}

void Figure::Shift(int dx, int dy)
{
	p1 = p1 + CPoint(dx, dy);
	p2 = p2 + CPoint(dx, dy);
	this->redefine(p1, p2);
}



void Figure::set_p1_x(LONG h)
{
	p1.x = h;
}

void Figure::set_p2_x(LONG h)
{
	p2.x = h;
}



void Figure::set_p1_y(LONG h)
{
	p1.y = h;
}

void Figure::set_p2_y(LONG h)
{
	p2.y = h;
}


LONG Figure::get_p1_x()
{
	return p1.x;
}

LONG Figure::get_p2_x()
{
	return p2.x;
}



LONG Figure::get_p1_y()
{
	return p1.y;
}

LONG Figure::get_p2_y()
{
	return p2.y;
}

CPoint Figure::get_p1() const
{
	return p1;
}

CPoint Figure::get_p2() const
{
	return p2;
}

void Figure::set_p1(CPoint & p)
{
	p1 = p;
}

void Figure::set_p2(CPoint & p)
{
	p2 = p;
}

