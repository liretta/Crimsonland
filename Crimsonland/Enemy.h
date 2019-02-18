#pragma once
#include "Framework.h"
#include "Sprites.h"
#include "Step.h"

class Enemy : public Sprite
{
	friend bool MoveEnemy(Sprite& target, Sprite& curObject);
};

//function for looking the next step for enemy
//return true if enemy has variatn to move, return false if enemy kill the player
//

