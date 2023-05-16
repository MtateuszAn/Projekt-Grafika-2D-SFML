#include "LineSegment.h"

LineSegment::LineSegment()
{
}

LineSegment::~LineSegment()
{
}

int LineSegment::BPx()
{
	return begPoint.xcord;
}

int LineSegment::BPy()
{
	return begPoint.ycord;
}

int LineSegment::EPx()
{
	return endPoint.xcord;
}

int LineSegment::EPy()
{
	return endPoint.ycord;
}

void LineSegment::SetBegPoint(int x, int y)
{
	begPoint.SetCords(x, y);
}

void LineSegment::SetEndPoint(int x, int y)
{
	endPoint.SetCords(x, y);
}

void LineSegment::draw()
{
}

void LineSegment::translate(int x, int y)
{
	this->begPoint.xcord = x;
	this->begPoint.ycord = y;
	this->endPoint.xcord = x;
	this->endPoint.ycord = y;
}

void LineSegment::rotate(int xo, int yo, int al)
{
	this->begPoint.xcord = xo + (begPoint.xcord - xo) * cos(al) - (begPoint.ycord - yo) * sin(al);
	this->begPoint.ycord = yo + (begPoint.xcord - xo) * sin(al) - (begPoint.ycord - yo) * cos(al);

	this->endPoint.xcord = xo + (endPoint.xcord - xo) * cos(al) - (endPoint.ycord - yo) * sin(al);
	this->endPoint.ycord = yo + (endPoint.xcord - xo) * sin(al) - (endPoint.ycord - yo) * cos(al);
}

void LineSegment::scale(int xo, int yo, int k)
{
	this->begPoint.xcord = begPoint.xcord * k + (1 - k) * xo;
	this->begPoint.ycord = begPoint.ycord * k + (1 - k) * yo;
	this->endPoint.xcord = endPoint.xcord * k + (1 - k) * xo;
	this->endPoint.ycord = endPoint.ycord * k + (1 - k) * yo;
}

