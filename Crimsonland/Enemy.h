#pragma once
#include "Framework.h"
#include "BaseGameObject.h"
#include "Step.h"

class Enemy : public GameObject
{
public:
	Enemy();
	friend bool MoveEnemy(Sprite& target, Sprite& curObject);
};

