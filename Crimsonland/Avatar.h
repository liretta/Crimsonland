#pragma once
#include "Framework.h"
#include "BaseGameObject.h"
#include "Step.h"

class Avatar : public GameObject
{
public:
	Avatar();
	friend bool MoveEnemy(Sprite& target, Sprite& curObject);
};