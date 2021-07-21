#include "pch.h"
#include "Pentagon.h"
IMPLEMENT_SERIAL(Pentagon, CObject, 1)

void Pentagon::Serialize(CArchive & ar)
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
		ar << p5;
		ar << p6;
		ar << p7;
		ar << p8;
		t1.Serialize(ar);
		t2.Serialize(ar);
		t3.Serialize(ar);

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
		ar >> p5;
		ar >> p6;
		ar >> p7;
		ar >> p8;
		t1.Serialize(ar);
		t2.Serialize(ar);
		t3.Serialize(ar);
	}
}

Pentagon::Pentagon(const CPoint & p1, const CPoint & p2):Figure(p1,p2)
{
}

void Pentagon::draw(CDC * dc) const
{
	CBrush myb(this->brush_color);
	dc->SelectObject(&myb);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(myp);
	CPoint arr[5] = { p3,p5,p7,p6,p4 };
	dc->Polygon(arr, 5);
}

void Pentagon::redefine(const CPoint & p1, const CPoint & p2)
{
	this->p1 = p1;
	this->p2 = p2;

	//אמצע
	this->p3 = (p1.x + p2.x) / 2;
	this->p3.y = p1.y;

	//שמאל עליון
	this->p4.x = p1.x;
	this-> p4.y = (p2.y + p1.y) / 2;
	//ימין עליון
	this->p5.x = p2.x;
	this->p5.y = (p2.y + p1.y) / 2;

	//שמאל תחתון
	this->p6.x = p1.x+(p2.x - p1.x) / 6;
	this->p6.y = p2.y;

	//ימין תחתון
	this->p7.x = p2.x - (p2.x - p1.x) / 6;
	this->p7.y = p2.y;
	t1.set_p1(p4);
	t1.set_p2(p3);
	t1.set_p3(p6);
	t2.set_p1(p3);
	t2.set_p2(p6);
	t2.set_p3(p7);
	t3.set_p1(p3);
	t3.set_p2(p7);
	t3.set_p3(p5);
}

bool Pentagon::isInside(const CPoint & P) const
{
	return (t1.isInside(P)||t2.isInside(P)||t3.isInside(P));
}
