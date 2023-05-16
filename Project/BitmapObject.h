#pragma once
#include "DrawableObject.h"

class BitmapObject: virtual public DrawableObject
{
	virtual void draw(sf::RenderWindow* window) = 0;
};

