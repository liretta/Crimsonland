#pragma once
#include "Framework.h"
#include <math.h>
#include <vector>
#include "BaseGameObject.h"

using std::vector;

//TODO: - cheng all function to game object
bool MoveEnemy(Sprite& target, Sprite& curObject);
bool LookingForNextStep(Sprite& target, Sprite& curObject, Point &newPoint);
vector <Point> FindNeighbors(Sprite& obj);
bool isCollusion(Point& obj1, int obj1W, int obj1H, Point& obj2, int obj2W, int obj2H);

int Diference(Point& a, Point&b);
