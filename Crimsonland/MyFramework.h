#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <direct.h>
#include "Framework.h"
#include "defines.h"
#include "Sprites.h"
#include "Game.h"

Game *playGame;
/* Test Framework realization */
class MyFramework : public Framework {

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 550;
		height = 500;
		fullscreen = false;
		playGame = new Game;
	}

	virtual bool Init()
	{	
		bool check = false;
		if (playGame != nullptr)
			check = playGame->InitGameObject();
		else
			check = false;
		return check;
	}

	virtual void Close()
	{
		//destroySprite
		delete playGame;
	}

	virtual bool Tick()
	{
		/*drawTestBackground();
		int x = avatar->GetX(), y = avatar->GetY();
		drawSprite(avatar, x, y);*/
		/*if (playGame->MoveEmenies())
		{
			playGame->DrawGameObject();
			return false;
		}
		else*/
			return true;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) 
	{
		//playGame->MoveAvatar(k);
	}

	virtual void onKeyReleased(FRKey k)
	{
		//playGame->MoveAvatar(k);
	}
};