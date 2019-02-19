#pragma once
#include "Sprites.h"

void Sprite::Init()
{
	curPosition.x = 0;
	curPosition.y = 0;
}

Point Sprite::GetCurPosition() const 
	{ return curPosition; }

int Sprite::GetX() const 
	{ return curPosition.x; }

int Sprite::GetY() const 
	{ return curPosition.y; }
	
void Sprite::SetCurPosition(Point& newPosition)
	{
		curPosition = newPosition;
		//curCenter.x = newPosition.x / 2;
		//curCenter.y = newPosition.y / 2;
	}

void Sprite::SetX(int x) 
{ 
	int w = 0, h = 0, wSprite=0, hSprite=0;
	getScreenSize(w, h);
	getSpriteSize(this, wSprite, hSprite);
	if (x >= 0 && x <= w - wSprite)
		curPosition.x = x;
	else
		curPosition.x = x < 0 ? 0: w - wSprite;
} 

void Sprite::SetY(int y) 
{ 
	int w = 0, h = 0, wSprite = 0, hSprite = 0;
	getScreenSize(w, h);
	getSpriteSize(this, wSprite, hSprite);
	if (y >= 0 && y <= h - hSprite)
		curPosition.y = y;
	else
		curPosition.y = y < 0 ? 0 : h - hSprite;
};
