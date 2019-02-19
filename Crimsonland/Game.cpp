#pragma once
#include "Game.h"

Game::Game()
{
	avatar = nullptr;
	enemy = nullptr;
}

bool Game::InitGameObject()
{
	//init Avatar
	char fullAvatar[_MAX_PATH];
	const char * path;
	if (_fullpath(fullAvatar, resourceAvatar, _MAX_PATH) != NULL)
		path = fullAvatar;
	else
		return false;
	avatar = new Avatar;
	avatar = (Avatar*)createSprite(path);
	avatar->Init();

	//init Enemy
	//TODO: create vector by enemies
	char fullEnemy[_MAX_PATH];
	const char * path2;
	if (_fullpath(fullEnemy, resourceEnemy, _MAX_PATH) != NULL)
		path2 = fullEnemy;
	else
		return false;
	enemy = (Enemy*)createSprite(path2);
	enemy->Init();

	//here ill be bullets initialization
	return true;
}

void Game::DrawGameObject()
{
	drawTestBackground();
	int x = avatar->GetX(), y = avatar->GetY();
	drawSprite(avatar, x, y);
	x = enemy->GetX(), y = enemy->GetY();
	drawSprite(enemy, x, y);

	//for the future:
	//for (int i =0; i< enemies.size(); ++i)
	//{
	//	x = enemies[i]->GetX(), y = enemies[i]->GetY();
	//	drawSprite(enemy[i], x,y);
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
	destroySprite(avatar);
	avatar = nullptr;
	destroySprite(enemy);
	enemy = nullptr;
	//for the future:
	//for (int i = 0; i<enemies.size(); ++i)
	//destroySprite(enemies[i]);
	//enemies.erase();
}

Game::~Game() {};
