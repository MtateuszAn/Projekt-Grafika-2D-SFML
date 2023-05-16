#pragma once
#include "Header.h"
#include"BitmapObject.h"
#include"AnimatedObject.h"

class SpriteObject: virtual public BitmapObject,AnimatedObject
{
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void animate() = 0;
};

