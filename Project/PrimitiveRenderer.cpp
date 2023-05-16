#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer()
{
	numOfpixels = 0;
	image.create(600, 600, sf::Color::Black);
	blank.create(600, 600, sf::Color::Black);
}

PrimitiveRenderer::~PrimitiveRenderer()
{
}

void PrimitiveRenderer::clearImage()
{
	image = blank;
}

bool PrimitiveRenderer::isColision(Point2D& p1, Point2D& p2, Point2D& p3, Point2D& p4)
{
	long s1 = p1.ReadXCords() * p3.ReadYCords() + p3.ReadXCords() * p4.ReadYCords() + p4.ReadXCords() * p1.ReadYCords() - p3.ReadYCords() * p4.ReadXCords() - p4.ReadYCords() * p1.ReadXCords() - p1.ReadYCords() * p3.ReadXCords();
	long s2 = p2.ReadXCords() * p3.ReadYCords() + p3.ReadXCords() * p4.ReadYCords() + p4.ReadXCords() * p2.ReadYCords() - p3.ReadYCords() * p4.ReadXCords() - p4.ReadYCords() * p2.ReadXCords() - p2.ReadYCords() * p3.ReadXCords();
	long s3 = p3.ReadXCords() * p1.ReadYCords() + p1.ReadXCords() * p2.ReadYCords() + p2.ReadXCords() * p3.ReadYCords() - p1.ReadYCords() * p2.ReadXCords() - p2.ReadYCords() * p3.ReadXCords() - p3.ReadYCords() * p1.ReadXCords();
	long s4 = p4.ReadXCords() * p1.ReadYCords() + p1.ReadXCords() * p2.ReadYCords() + p2.ReadXCords() * p4.ReadYCords() - p1.ReadYCords() * p2.ReadXCords() - p2.ReadYCords() * p4.ReadXCords() - p4.ReadYCords() * p1.ReadXCords();

	if ((s1 < 0 && s2>0 && s3 > 0 && s4 < 0) || (s1 > 0 && s2 < 0 && s3 < 0 && s4 > 0))
		return true;
	return false;
}


//rysowanie lini algorytmem
void PrimitiveRenderer::makeLineAlgPrzyrost(int x0, int y0, int x1, int y1)
{

	if((x0-x1)+(y0-y1)<=0){
		double xi = x0, yi = y0;
		this->image.setPixel(x0,y0,sf::Color::White);
		double dx = x1 - x0;
		double dy = y1 - y0;
		double m = dy / dx;
		numOfpixels = 1;
		if (m<1&&m>-1) {
			for (int i = x0; i < x1; i++)
			{
				xi++;
				yi = m + yi;
				this->image.setPixel(xi, yi, sf::Color::White);
				numOfpixels++;
			}
		}
		else {
			m = dx / dy;
			for (int i = y0; i < y1; i++)
			{
				yi++;
				xi = m + xi;
				this->image.setPixel(xi, yi, sf::Color::White);
				numOfpixels++;
			}
		}
	}
	else {
		double xi = x1, yi = y1;
		this->image.setPixel(x1, y1, sf::Color::White);
		double dx = x0 - x1;
		double dy = y0 - y1;
		double m = dy / dx;
		numOfpixels = 1;
		if (m<1 && m>-1) {
			for (int i = x1; i < x0; i++)
			{
				xi++;
				yi = m + yi;
				this->image.setPixel(xi, yi, sf::Color::White);
				numOfpixels++;
			}
		}
		else {
			m = dx / dy;
			for (int i = y1; i < y0; i++)
			{
				yi++;
				xi = m + xi;
				//vertexArray[numOfpixels] = sf::Vertex(sf::Vector2f(xi, yi));
				this->image.setPixel(xi, yi, sf::Color::White);
				numOfpixels++;
			}
		}
	}

	
}

void PrimitiveRenderer::makePoint(Point2D point)
{
	this->image.setPixel(point.ReadXCords(), point.ReadYCords(), point.color);
}


//rysowanie z osmiokrotna symetria
void PrimitiveRenderer::makeCircle(int xc, int yc, float r)
{
	float a, step;
	int x, y;
	step = 1.0f / r;

	for (a = 0; a <3.141592f/4; a += step) {
		x = 0 + r * cos(a) + 0.5f; // Zaokr¹glone X
		y = 0 + r * sin(a) + 0.5f; // Zaokr¹glone Y
		this->image.setPixel(x+xc, y+yc, sf::Color::White);
		this->image.setPixel(( - x) + xc, y + yc, sf::Color::White);
		this->image.setPixel(x + xc, (-y)+yc, sf::Color::White);
		this->image.setPixel((-x) + xc, (-y)+yc, sf::Color::White);
		this->image.setPixel(y + xc, x + yc, sf::Color::White);
		this->image.setPixel((-y) + xc, x + yc, sf::Color::White);
		this->image.setPixel(y + xc, (-x) + yc, sf::Color::White);
		this->image.setPixel((-y) + xc, (-x) + yc, sf::Color::White);
	}

}
void PrimitiveRenderer::makeElipse(int xc, int yc, float rx, float ry) 
{
	int x, y;
	int xSym, ySym;
	int xAbs, yAbs;
	if (rx <= 0 || ry < 0)
		return;
	float stepY = (float)1 / ry;
	float stepX = (float)1 / rx;
	float step = stepY;

	if (rx * rx * (xc + rx * cos(0) + 0.5) > ry * ry * (yc + ry * sin(0) + 0.5))
		step = stepX;
	else
		step = stepY;

	float i = 0;
	while (i < 3.141592f/2)
	{
		x = xc + rx * cos(i) + 0.5;
		y = yc + ry * sin(i) + 0.5;

		if (rx * rx * x > ry * ry * y)
			i += stepX;
		else
			i += stepY;

		xAbs = abs(xc - x);
		yAbs = abs(yc - y);
		xSym = x - (xAbs + xAbs);
		ySym = y - (yAbs + yAbs);

		this->image.setPixel(x, y, sf::Color::White);
		this->image.setPixel(x, ySym, sf::Color::White);
		this->image.setPixel(xSym, y, sf::Color::White);
		this->image.setPixel(xSym, ySym, sf::Color::White);
	}
}


void PrimitiveRenderer::makeLineFromPoints(Point2D point2D[], int numberOfPoints)
{
	for (int i = 0; i < numberOfPoints-1; i++)
	{
		this -> makeLineAlgPrzyrost(point2D[i].ReadXCords(), point2D[i].ReadYCords(), point2D[i+1].ReadXCords(), point2D[i+1].ReadYCords());
	}

}

void PrimitiveRenderer::makeShape(Point2D point2D[], int numberOfPoints)
{
	for (int i = 0; i < numberOfPoints + 1; i++)
	{
		if (i > 1)
		{
			int j = 0;
			while ((j + 1) < i)
			{
				if (isColision(point2D[j], point2D[j + 1], point2D[i - 1], point2D[i]))
					return;
				j++;
			}
		}
	}
	int i;
	for (i = 0; i < numberOfPoints - 1; i++)
	{
		this->makeLineAlgPrzyrost(point2D[i].ReadXCords(), point2D[i].ReadYCords(), point2D[i + 1].ReadXCords(), point2D[i + 1].ReadYCords());
	}
	this->makeLineAlgPrzyrost(point2D[0].ReadXCords(), point2D[0].ReadYCords(), point2D[i].ReadXCords(), point2D[i].ReadYCords());
}

void PrimitiveRenderer::makeRectangle(Point2D p1, Point2D p2)
{
	this->makeLineAlgPrzyrost(p1.ReadXCords(),p1.ReadYCords(),p1.ReadXCords(),p2.ReadYCords() );
	this->makeLineAlgPrzyrost(p1.ReadXCords(), p2.ReadYCords(), p2.ReadXCords(), p2.ReadYCords());
	this->makeLineAlgPrzyrost(p2.ReadXCords(), p2.ReadYCords(), p2.ReadXCords(), p1.ReadYCords());
	this->makeLineAlgPrzyrost(p2.ReadXCords(), p1.ReadYCords(), p1.ReadXCords(), p1.ReadYCords());
}
void PrimitiveRenderer::makeRectangle(Point2D p1, Point2D p2, sf::Color filcolor)
{
	this->makeLineAlgPrzyrost(p1.ReadXCords(), p1.ReadYCords(), p1.ReadXCords(), p2.ReadYCords());
	this->makeLineAlgPrzyrost(p1.ReadXCords(), p2.ReadYCords(), p2.ReadXCords(), p2.ReadYCords());
	this->makeLineAlgPrzyrost(p2.ReadXCords(), p2.ReadYCords(), p2.ReadXCords(), p1.ReadYCords());
	this->makeLineAlgPrzyrost(p2.ReadXCords(), p1.ReadYCords(), p1.ReadXCords(), p1.ReadYCords());
	this->floodfill(Point2D((p1.ReadXCords() + p2.ReadXCords()) / 2, (p1.ReadYCords() + p2.ReadYCords()) / 2),filcolor);
}

void PrimitiveRenderer::floodfill(Point2D start, sf::Color filColor)
{
	Point2D p(0, 0, 1, filColor);

	sf::Color baseColor = image.getPixel(start.ReadXCords(), start.ReadYCords());
	
	std::stack<Point2D> stack;
	stack.push(start);
	while (!stack.empty())
	{

		p.SetCords(stack.top().ReadXCords(), stack.top().ReadYCords());
		stack.pop();
		if (image.getPixel(p.ReadXCords(), p.ReadYCords()) == filColor)
			continue;
		if (image.getPixel(p.ReadXCords(), p.ReadYCords()) != baseColor)
			continue;

		this->makePoint(p);
		image.setPixel(p.ReadXCords(), p.ReadYCords(), filColor);

		if (p.ReadYCords() - 1 > 0)
			stack.push(Point2D(p.ReadXCords(), p.ReadYCords() - 1));

		if (p.ReadYCords() + 1 < 600)
			stack.push(Point2D(p.ReadXCords(), p.ReadYCords() + 1));

		if (p.ReadYCords() - 1 > 0)
			stack.push(Point2D(p.ReadXCords() - 1, p.ReadYCords()));

		if (p.ReadYCords() + 1 < 600)
			stack.push(Point2D(p.ReadXCords() + 1, p.ReadYCords()));

	}



}

void PrimitiveRenderer::boundryfill(Point2D start, sf::Color filColor, sf::Color borderColor)
{
	Point2D p(0, 0, 1, filColor);


	std::stack<Point2D> stack;
	stack.push(start);
	while (!stack.empty())
	{

		p.SetCords(stack.top().ReadXCords(), stack.top().ReadYCords());
		stack.pop();
		if (image.getPixel(p.ReadXCords(), p.ReadYCords()) == filColor)
			continue;
		if (image.getPixel(p.ReadXCords(), p.ReadYCords()) == borderColor)
			continue;

		this->makePoint(p);
		image.setPixel(p.ReadXCords(), p.ReadYCords(), filColor);

		if (p.ReadYCords() - 1 > 0)
			stack.push(Point2D(p.ReadXCords(), p.ReadYCords() - 1));

		if (p.ReadYCords() + 1 < 600)
			stack.push(Point2D(p.ReadXCords(), p.ReadYCords() + 1));

		if (p.ReadXCords() - 1 > 0)
			stack.push(Point2D(p.ReadXCords() - 1, p.ReadYCords()));

		if (p.ReadXCords() + 1 < 600)
			stack.push(Point2D(p.ReadXCords() + 1, p.ReadYCords()));

	}

}