#include "Point2D.h"

Point2D::Point2D()
{
	xcord = 0;
	ycord = 0;
	thickness = 1;
	color = sf::Color::White;
}

Point2D::Point2D(int xcord, int ycord)
{
	this->xcord = xcord;
	this->ycord = ycord;
	thickness = 1;
	color = sf::Color::White;
}

Point2D::Point2D(int xcord, int ycord, int thickness, sf::Color color)
{
	this->xcord = xcord;
	this->ycord = ycord;
	this->color = color;
	this->thickness = thickness;
}


Point2D::~Point2D()
{
}

int Point2D::ReadXCords()
{
	return xcord;
}

int Point2D::ReadYCords()
{
	return ycord;
}

void Point2D::SetCords(int x, int y)
{
	this->xcord = x;
	this->ycord = y;
}

void Point2D::draw(sf::RenderWindow* window)
{
}

void Point2D::translate(int x, int y)
{
	this->xcord = x;
	this->ycord = y;
}

void Point2D::rotate(int xo, int yo, int al)
{
	this->xcord = xo + (xcord - xo) * cos(al) - (ycord - yo) * sin(al);
	this->ycord = yo + (xcord - xo) * sin(al) - (ycord - yo) * cos(al);
}

void Point2D::scale(int xo, int yo, int k)
{
	this->xcord = xcord * k + (1 - k) * xo;
	this->ycord = ycord * k + (1 - k) * yo;
}


