#pragma once

#include <stack>
#include "Header.h"
#include "LineSegment.h"
#include "Point2D.h"

class PrimitiveRenderer //: virtual public ShapeObject
{
public:
	

	//zmienne:
	
	sf::Image image;
	sf::Image blank;
	

	

	int numOfpixels;

	//metody
	PrimitiveRenderer();
	~PrimitiveRenderer();

	
	//dzialajace
	void floodfill(Point2D start, sf::Color filcolor);
	void boundryfill(Point2D start, sf::Color filcolor, sf::Color borderColor);
	void makePoint(Point2D point);
	bool isColision(Point2D& p1, Point2D& p2, Point2D& p3, Point2D& p4);
	void makeLineAlgPrzyrost(int x0, int y0, int x1, int y1);
	void makeLineFromPoints(Point2D point2D[],int numberOfPoints);
	void makeCircle(int xc, int yc, float r);
	void makeElipse(int xc, int yc, float rx, float ry);
	void makeShape(Point2D point2D[], int numberOfPoints);
	void makeRectangle(Point2D p1, Point2D p2);
	void makeRectangle(Point2D p1, Point2D p2, sf::Color filcolor);
	void clearImage();

	void draw();
	void translate(int x, int y);
	void rotate(int xo, int yo, int al);
	void scale(int xo, int yo, int k);
};

