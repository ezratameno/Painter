#pragma once
#include"framework.h"
class Figure :public CObject
{
	DECLARE_SERIAL(Figure)
protected:
	CPoint p1, p2;
	COLORREF brush_color, pen_color;
	int pen_size;
public:
	virtual void Serialize(CArchive& ar);
	Figure(const CPoint& p1, const CPoint& p2);
	virtual void change_brush_color(const COLORREF b);
	virtual void change_pen_color_and_size(const COLORREF p, int t);
	virtual void draw(CDC *dc)const;
	virtual void redefine(const CPoint& p1,const CPoint& p2);
	virtual bool isInside(const CPoint &P)const;
	virtual void Shift(int dx, int dy);
	Figure() {}
	void set_p1_x(LONG h);
	void set_p2_x(LONG h);
	void set_p1_y(LONG h);
	void set_p2_y(LONG h);
	LONG get_p1_x();
	LONG get_p2_x();
	LONG get_p1_y();
	LONG get_p2_y();
	CPoint get_p1()const;
	CPoint get_p2() const;
	void set_p1(CPoint &p);
	void set_p2(CPoint &p);
};

