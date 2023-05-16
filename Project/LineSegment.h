#pragma once

#include "Header.h"
#include "Point2D.h"

class LineSegment//: virtual public ShapeObject
{
public:
	Point2D begPoint;
	Point2D endPoint;

	LineSegment();
	~LineSegment();
	
	int BPx();
	int BPy();
	int EPx();
	int EPy();
	void SetBegPoint(int x, int y);
	void SetEndPoint(int x, int y);

	void draw();
	void translate(int x, int y);
	void rotate(int xo, int yo, int al);
	void scale(int xo, int yo, int k);
};

