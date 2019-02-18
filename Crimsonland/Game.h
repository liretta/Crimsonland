#pragma once
#include "Framework.h"
#include "defines.h"
#include "Sprites.h"
#include"Avatar.h"
#include "Enemy.h"
#include "Step.h"

//TODO:
//create game-class - it will be global object? 
//members - pointers to avatar, enemy (then will be enemy's vector), bollet
//call this functions in framework
//constructor - init null-ptr all pointers
//create game-objects - createSprite, initialize size and startPoint
//Draw - colled step-function and all draw function
//endGame - delete all sprites, make all pointers - null ptr