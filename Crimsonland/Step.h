#pragma once
#include "Framework.h"
#include <math.h>
#include <vector>
#include "BaseGameObject.h"

using std::vector;

//TODO: - cheng all function to game object
bool LookingForNextStep(GameObject* target, GameObject* curObject, Point &newPoint);
vector <Point> FindNeighbors(GameObject* obj);
bool isCollusion(Point& obj1, int obj1W, int obj1H, Point& obj2, int obj2W, int obj2H);

int Diference(Point& a, Point&b);
