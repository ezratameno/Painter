#include "pch.h"
#include "Arrow.h"
IMPLEMENT_SERIAL(Arrow, CObject, 1)

void Arrow::Serialize(CArchive & ar)
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
		ar << p9;
		rec.Serialize(ar);
		t.Serialize(ar);
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
		ar >> p9;
		rec.Serialize(ar);
		t.Serialize(ar);
	}
}

Arrow::Arrow(const CPoint & p1, const CPoint & p2):Figure(p1,p2)
{
}

void Arrow::draw(CDC * dc) const
{
	CBrush myb(this->brush_color);
	dc->SelectObject(&myb);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(myp);
	CPoint arr[7] = {p3,p5,p7,p9,p8,p6,p4};
	dc->Polygon(arr, 7);
}

void Arrow::redefine(const CPoint & p1, const CPoint & p2)
{
	this->p1 = p1;
	this->p2 = p2;

	//מלבן

	//שמאל עליון
	this->p3.x = p1.x;
	this->p3.y = p1.y + (p2.y - p1.y) / 4;
	//שמאל תחתון
	this->p4.x = p1.x;
	this->p4.y = p2.y - (p2.y - p1.y) / 4;

	//ימין עליון
	this->p5.x = (p1.x + p2.x) / 2;
	this->p5.y = p1.y + (p2.y - p1.y) / 4;

	//ימין תחתון

	this->p6.x = (p1.x + p2.x) / 2;
	this->p6.y = p2.y - (p2.y - p1.y) / 4;

	//משולש
	//עליון
	this->p7.x = (p1.x + p2.x) / 2;
	this->p7.y = p1.y;

	//תחתון
	this->p8.x = (p1.x + p2.x) / 2;
	this->p8.y = p2.y;

	//אמצע
	this->p9.y = (p1.y + p2.y) / 2;
	this->p9.x = p2.x;
	//מלבן
	rec.set_p1(p3);
	rec.set_p2(p6);
	//משולש
	t.set_p1(p7);
	t.set_p2(p8);
	t.set_p3(p9);
}

bool Arrow::isInside(const CPoint & P) const
{
	return(t.isInside(P) || rec.isInside(P));
	
}
