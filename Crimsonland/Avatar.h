#pragma once
#include "Framework.h"
#include "Sprites.h"
#include "Step.h"

class Avatar : public Sprite
{
public:
	void Init();
	friend bool MoveEnemy(Sprite& target, Sprite& curObject);
};