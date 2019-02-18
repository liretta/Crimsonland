#include "Avatar.h"

void Avatar::AvatarInit()
{
	int x = 0, y = 0;
	getScreenSize(x, y);
	curPosition.x = x / 2;
	curPosition.y = y / 2;
}