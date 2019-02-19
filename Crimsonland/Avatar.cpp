#pragma once
#include "Avatar.h"

void Avatar::Init()
{
	int x = 0, y = 0;
	getScreenSize(x, y);
	int wAvatar = 0, hAvatar = 0;
	getSpriteSize(this, wAvatar, hAvatar);
	curPosition.x = x / 2-wAvatar/2;
	curPosition.y = y / 2-hAvatar/2;
}