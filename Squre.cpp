#include "pch.h"
#include "Squre.h"

IMPLEMENT_SERIAL(Squre, CObject, 1)

Squre::Squre(const CPoint& p1, const CPoint& p2) :Rectangle_my(p1, p2)
{
}

void Squre::draw(CDC * dc) const
{
	
	CBrush myb(this->brush_color);
	dc->SelectObject(&myb);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(myp);
	CPoint arr[4] = { p1,p3,p2,p4 };
	dc->Polygon(arr, 4);
}

void Squre::redefine(const CPoint& p1, const CPoint& p2)
{
	this->p1 = p1;
	this->p2 = p2;
	side = p2.x - p1.x;
	p3.x = p1.x + side;
	p3.y = p1.y;
	p4.x = p1.x;
	p4.y = p1.y + side;
	this->p2.x = p3.x;
	this->p2.y = p4.y;
}

bool Squre::isInside(const CPoint & s) const
{
	return (s.x >= p1.x&&s.x <= p3.x &&s.y >= p1.y&&s.y <= p4.y);
}

void Squre::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		ar << p1;
		ar << p2;
		ar << brush_color;
		ar << pen_color;
		ar << pen_size;
		ar << p3;
		ar << p4;
		ar << side;
	}
	else // Loading, not storing
	{
		ar >> p1;
		ar >> p2;
		ar >> brush_color;
		ar >> pen_color;
		ar >> pen_size;
		ar >> p3;
		ar >> p4;
		ar >> side;
	}
}


