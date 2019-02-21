#pragma once
#include "Avatar.h"
#include "defines.h"



Avatar::Avatar()
{
	//TODO: try-catch block if result by _fullpath == null
	char fullAvatar[_MAX_PATH];
	const char * path;
	_fullpath(fullAvatar, resourceAvatar, _MAX_PATH);
	path = fullAvatar;
	sprite = createSprite(path);
	
	int x = 0, y = 0;
	getScreenSize(x, y);
	int wAvatar = 0, hAvatar = 0;
	getSpriteSize(sprite, wAvatar, hAvatar);
	curPosition.x = x / 2-wAvatar/2;
	curPosition.y = y / 2-hAvatar/2;
}