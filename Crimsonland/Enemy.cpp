#pragma once
#include "Enemy.h"
#include <time.h>




void Enemy::Init()
{
	std::srand((unsigned int)time(0));
	int wScreen = 0, hScreen = 0;
	getScreenSize(wScreen, hScreen);
	
	int wEnemy = 0, hEnemy = 0;
	getSpriteSize(this, wEnemy, hEnemy);
	int x = rand() % (wScreen-wEnemy);
	int y = rand() % (hScreen - hEnemy);
	curPosition.x = x;
	curPosition.y = y;
}