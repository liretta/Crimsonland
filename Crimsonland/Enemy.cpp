#pragma once
#include "Enemy.h"
#include "defines.h"
#include <time.h>

Enemy::Enemy()
{
	//TODO: added try-catch block, if cannot open path
	char fullAvatar[_MAX_PATH];
	const char * path;
	_fullpath(fullAvatar, resourceEnemy, _MAX_PATH);
	path = fullAvatar;
	sprite = createSprite(path);

	std::srand((unsigned int)time(0));
	int wScreen = 0, hScreen = 0;
	getScreenSize(wScreen, hScreen);
	
	int wEnemy = 0, hEnemy = 0;
	getSpriteSize(sprite, wEnemy, hEnemy);
	int x = rand() % (wScreen-wEnemy);
	int y = rand() % (hScreen - hEnemy);
	curPosition.x = x;
	curPosition.y = y;
}