#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <direct.h>
#include "Framework.h"
#include "defines.h"
#include "Sprites.h"

/* Test Framework realization */
class MyFramework : public Framework {

public:
	Sprite* avatar;
	

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 550;
		height = 500;
		fullscreen = false;
	}

	virtual bool Init()
	{
		char full[_MAX_PATH];
		const char * path;
		if (_fullpath(full, resourceAvatar, _MAX_PATH) != NULL)
			path = full;
		else
			return false;

		avatar = createSprite(path);
		avatar->Init();
		
		return true;
	}

	virtual void Close()
	{
		//destroySprite
	}

	virtual bool Tick()
	{
		//call function MoveEnemy with all avatar and all enemies
		//if(MoveEnemy()
		drawTestBackground();
		int x = avatar->GetX(), y = avatar->GetY();
		drawSprite(avatar, x, y);
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) 
	{
		int x = avatar -> GetX();
		int y = avatar-> GetY();
		switch (k)
		{
		case FRKey::RIGHT:
			x+=10;
			break;
		case FRKey::LEFT:
			x-=10;
			break;
		case FRKey::DOWN:
			y+=10;
			break;
		case FRKey::UP:
			y-=10;
			break;
		case FRKey::COUNT:
			break;
		default:
			break;
		}
		avatar->SetX(x);
		avatar->SetY(y);
	}

	virtual void onKeyReleased(FRKey k)
	{
		int x = avatar->GetX();
		int y = avatar->GetY();
		switch (k)
		{
		case FRKey::RIGHT:
			x += 10;
			break;
		case FRKey::LEFT:
			x -= 10;
			break;
		case FRKey::DOWN:
			y += 10;
			break;
		case FRKey::UP:
			y -= 10;
			break;
		case FRKey::COUNT:
			break;
		default:
			break;
		}
		avatar->SetX(x);
		avatar->SetY(y);
	}
};