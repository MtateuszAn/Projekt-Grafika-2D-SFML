#pragma once
#include "GameObject.h"
class UpdatableObject: virtual public GameObject
{
	virtual void update() = 0;
};

