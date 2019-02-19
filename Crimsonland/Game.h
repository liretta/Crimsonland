#pragma once
#include "Framework.h"
#include "defines.h"
#include "BaseGameObject.h"
#include "Avatar.h"
#include "Enemy.h"
#include "Step.h"

//TODO:
//create game-class - it will be global object
//members - pointers to avatar, enemy (then will be enemy's vector), bullet
//call this functions in framework
//constructor - init null-ptr all pointers
//create game-objects - createSprite, initialize size and startPoint
//Draw - colled step-function and all draw function (background, objects)
//endGame - delete all sprites, make all pointers - null ptr

class Game
{
private:
	Avatar* avatar;
	Enemy* enemy;
	//vector <Enemy*> enemies;
	//vector <Bullet> cartridges;
public:
	Game();
	void DrawGameObject(); //called draw-functions for backgroung, avatar, enemies
	void MoveAvatar(const FRKey &k); //
	bool MoveEmenies();
	void DeleteObjects();
	~Game();
};