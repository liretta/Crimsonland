#pragma once
#include "Framework.h"
#include "Avatar.h"
#include "Enemy.h"
#include "Step.h"

using std::vector;

//1. Looking for nearest neighbors cell on screen of cur enemy
//2. looking best step

int Diference(Point& a, Point&b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isCollusion(Point& obj1, int obj1W, int obj1H, Point& obj2, int obj2W, int obj2H)
{
	bool xColl = false, yColl = false;

	if ((obj1.x + obj1W >= obj2.x) && (obj1.x <= obj2.x + obj2W))
		xColl = true;
	if ((obj1.y + obj1H >= obj2.y) && (obj1.y <= obj2.y + obj2H))
		yColl = true;

	return (xColl&&yColl);
}

vector <Point> FindNeighbors(GameObject* obj)
{
	vector <Point> vNeighbors;
	Point tempP, objPoint = obj->GetCurPosition();
	int wObj = 0, hObj = 0;
	getSpriteSize(obj->sprite, wObj, hObj);

	//lookin all neighbors: from top-left to left
	vector <int> forX = { -wObj, 0, wObj, wObj, wObj, 0, -wObj, -wObj };
	vector <int> forY = { -hObj, -hObj, -hObj, 0, hObj, hObj, hObj, 0 };

	int wScreen = 0, hScreen = 0;
	getScreenSize(wScreen, hScreen);

	int n = forX.size();
	for (int i = 0; i < n; ++i)
	{
		tempP = objPoint;
		if (objPoint.x + forX[i] >= 0 && objPoint.x + forX[i] <= wScreen)
			tempP.x = objPoint.x + forX[i];

		if (objPoint.y + forY[i] >= 0 && objPoint.y + forY[i] <= hScreen)
			tempP.y = objPoint.y + forY[i];
		vNeighbors.push_back(tempP);
	}

	return(move(vNeighbors));
}

//return true if we can move enemy, return false if one of the nearest neighbors is avatar (game over)
bool LookingForNextStep(GameObject* target, GameObject* curObject, Point &newPoint)
{
	//1. lookign nearest neighbors
	bool isAvatarNeer = false;
	vector <Point> vNeighbors = FindNeighbors(curObject);

	Point targetPoint = target->GetCurPosition();
	int targetW = 0, targetH = 0;
	getSpriteSize(target->sprite, targetW, targetH);

	int objW = 0, objH = 0;
	getSpriteSize(curObject->sprite, objW, objH);

	int w = 0, h = 0;
	getScreenSize(w, h);
	int bestCost = w * h, stepCost = 0;
	newPoint = vNeighbors[0];
	for (int i = 0; i < vNeighbors.size(); ++i)
	{
		isAvatarNeer = isCollusion(targetPoint, targetW, targetH, vNeighbors[i], objW, objH);
		if (isAvatarNeer)
			return false;
		stepCost = Diference(targetPoint, vNeighbors[i]);
		if (stepCost < bestCost)
		{
			bestCost = stepCost;
			newPoint = vNeighbors[i];
		}
	}
	return true;
}



