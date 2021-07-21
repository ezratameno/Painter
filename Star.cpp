#include "pch.h"
#include "Star.h"
IMPLEMENT_SERIAL(Star, CObject, 1)

void Star::Serialize(CArchive & ar)
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
	ar << p10;
	rec.Serialize(ar);
	t1.Serialize(ar);
	t2.Serialize(ar);
	t3.Serialize(ar);
	t4.Serialize(ar);
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
	ar >> p10;
	rec.Serialize(ar);
	t1.Serialize(ar);
	t2.Serialize(ar);
	t3.Serialize(ar);
	t4.Serialize(ar);
	}
}

Star::Star(const CPoint & p1, const CPoint & p2):Figure(p1,p2)
{
}

void Star::draw(CDC * dc) const
{
	CBrush myb(this->brush_color);
	dc->SelectObject(&myb);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(myp);
	CPoint arr[8] = { p3,p4,p6,p7,p9,p8,p10,p5};
	dc->Polygon(arr, 8);
}

void Star::redefine(const CPoint & p1, const CPoint & p2)
{
	this->p1 =p1;
	this->p2 = p2;

	//קודקוד עליון
	p6.x = (p1.x + p2.x) / 2;
	p6.y = p1.y;

	//קודקוד ימני
	p9.x = p2.x;
	p9.y = (p1.y + p2.y) / 2;

	//קודקוד שמאלי
	p3.x = p1.x;
	p3.y = (p1.y + p2.y) / 2;

	//קודקוד תחתון
	p10.x = (p1.x + p2.x) / 2;
	p10.y = p2.y;

	p4.y = p3.y - (p3.y - p1.y) / 5;
	p4.x = p3.x +(p2.x -p1.x)/3;

	p7.y = p4.y;
	p7.x = p9.x - (p2.x - p1.x) / 3;

	p5.x = p4.x;
	p5.y = p3.y + (p3.y - p1.y) / 5;

	p8.x = p7.x;
	p8.y = p5.y;
	
	rec.set_p1(p4);
	rec.set_p2(p8);
	t1.set_p1(p3);
	t1.set_p2(p4);
	t1.set_p3(p5);
	t2.set_p1(p4);
	t2.set_p2(p6);
	t2.set_p3(p7);
	t3.set_p1(p7);
	t3.set_p2(p9);
	t3.set_p3(p8);
	t4.set_p1(p8);
	t4.set_p2(p10);
	t4.set_p3(p5);
}

bool Star::isInside(const CPoint & P) const
{
	return (rec.isInside(P)||t1.isInside(P)||t2.isInside(P)||t3.isInside(P)||t4.isInside(P));
}
