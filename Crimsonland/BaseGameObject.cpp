#pragma once
#include "BaseGameObject.h"

GameObject::GameObject() 
{
	sprite = nullptr;
}

Point GameObject::GetCurPosition() const
	{ return curPosition; }

int GameObject::GetX() const
	{ return curPosition.x; }

int GameObject::GetY() const
	{ return curPosition.y; }
	
void GameObject::SetCurPosition(Point& newPosition)
	{
		curPosition = newPosition;
		//curCenter.x = newPosition.x / 2;
		//curCenter.y = newPosition.y / 2;
	}

void GameObject::SetX(int x)
{ 
	int w = 0, h = 0, wSprite=0, hSprite=0;
	getScreenSize(w, h);
	getSpriteSize(sprite, wSprite, hSprite);
	if (x >= 0 && x <= w - wSprite)
		curPosition.x = x;
	else
		curPosition.x = x < 0 ? 0: w - wSprite;
} 

void GameObject::SetY(int y)
{ 
	int w = 0, h = 0, wSprite = 0, hSprite = 0;
	getScreenSize(w, h);
	getSpriteSize(sprite, wSprite, hSprite);
	if (y >= 0 && y <= h - hSprite)
		curPosition.y = y;
	else
		curPosition.y = y < 0 ? 0 : h - hSprite;
};
