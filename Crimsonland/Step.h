#pragma once
#include "Framework.h"
#include <math.h>
#include <vector>
#include "Sprites.h"

using std::vector;

bool MoveEnemy(Sprite& target, Sprite& curObject);
bool LookingForNextStep(Sprite& target, Sprite& curObject, Point &newPoint);
vector <Point> FindNeighbors(Sprite& obj);
bool isCollusion(Point& obj1, int obj1W, int obj1H, Point& obj2, int obj2W, int obj2H);

int Diference(Point& a, Point&b);
