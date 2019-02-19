#pragma once
#include "Game.h"

Game::Game()
{
	avatar = new Avatar;
	enemy = new Enemy;
}

void Game::DrawGameObject()
{
	drawTestBackground();
	int x = avatar->GetX(), y = avatar->GetY();
	drawSprite(avatar->sprite, x, y);
	x = enemy->GetX(), y = enemy->GetY();
	drawSprite(enemy->sprite, x, y);

	//for the future:
	//for (int i =0; i< enemies.size(); ++i)
	//{
	//	x = enemies[i]->GetX(), y = enemies[i]->GetY();
	//	drawSprite(enemy[i]->sprite, x,y);
};
void Game::MoveAvatar(const FRKey &k)
{
	int x = avatar->GetX(), y = avatar->GetY();
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

bool Game::MoveEmenies() { return true; };
void Game::DeleteObjects()
{
	destroySprite(avatar->sprite);
	avatar = nullptr;
	destroySprite(enemy->sprite);
	enemy = nullptr;
	//for the future:
	//for (int i = 0; i<enemies.size(); ++i)
	//destroySprite(enemies[i]);
	//enemies.erase();
}

Game::~Game() 
{
	if (avatar != nullptr)
		delete avatar;
	if (enemy != nullptr)
		delete enemy;
};
