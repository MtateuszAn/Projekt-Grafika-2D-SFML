#pragma once
#include "Header.h"
#include "ShapeObject.h"

class Point2D//: virtual public ShapeObject
{
public:
	//x y cordynates of point
	int xcord;
	int ycord;
	int thickness;
	sf::Color color;
	Point2D();
	Point2D(int xcord,int ycord);
	Point2D(int xcord,int ycord, int thickness, sf::Color color);
	~Point2D();

	int ReadXCords();
	int ReadYCords();
	void SetCords(int x, int y);

	void draw(sf::RenderWindow* window);
	void translate(int x, int y);
	void rotate(int xo,int yo, int al);
	void scale(int xo, int yo, int k);


	//void draw(RenderWindow* window);
};

