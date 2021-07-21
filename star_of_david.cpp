#include "pch.h"
#include "star_of_david.h"
IMPLEMENT_SERIAL(star_of_david, CObject, 1)

void star_of_david::draw(CDC * dc) const
{
	
	CBrush myb(this->brush_color);
	dc->SelectObject(&myb);
	CPen myp(PS_SOLID, pen_size, pen_color);
	dc->SelectObject(myp);
	CPoint arr[12] = {p3,p10,p4,p11,p5,p12,p6,p13,p7,p14,p8,p9};
	dc->Polygon(arr, 12);
}

void star_of_david::redefine(const CPoint & p1, const CPoint & p2)
{

	this->p1 = p1;
	this->p2 = p2;
	
	//משולש תחתון
	//שמאל
	p3.x = p1.x;
	p3.y = p1.y + (p2.y - p1.y) / 4;

	//	אמצע
	p7.y = p2.y;
	p7.x = (p1.x + p2.x)/2;

	//ימין
	p5.x = p2.x;
	p5.y = p3.y;

	//משולש עליון
	//שמאל
	p8.x = p1.x;
	p8.y = p2.y - (p2.y - p1.y) / 4;

	//ימין
	p6.x = p2.x;
	p6.y = p8.y;

	//אמצע
	p4.x = p7.x;
	p4.y = p1.y;

	p9.x = p1.x + (p2.x - p1.x) / 6;
	p9.y = (p1.y + p2.y) / 2;
	
	p12.y = p9.y;
	p12.x = p2.x - (p2.x - p1.x) / 6;

	p10.x = p1.x + (p2.x - p1.x) / 3;
	p10.y = p3.y;

	p11.y = p10.y;
	p11.x = p2.x - (p2.x - p1.x) / 3;

	p14.x = p10.x;
	p14.y = p8.y;

	p13.x = p11.x;
	p13.y = p8.y;
	t1.set_p1(p3);
	t1.set_p2(p5);
	t1.set_p3(p7);
	t2.set_p1(p8);
	t2.set_p2(p6);
	t2.set_p3(p4);

}

bool star_of_david::isInside(const CPoint & P) const
{
		return (t1.isInside(P)||t2.isInside(P));


}


star_of_david::star_of_david(const CPoint & p1, const CPoint & p2):Figure(p1,p2)
{
}

void star_of_david::Serialize(CArchive & ar)
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
		ar << p11;
		ar << p12;
		ar << p13;
		ar << p14;
		t1.Serialize(ar);
		t2.Serialize(ar);
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
		ar >> p11;
		ar >> p12;
		ar >> p13;
		ar >> p14;
		t1.Serialize(ar);
		t2.Serialize(ar);
		
	}


}
