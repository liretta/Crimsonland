#pragma once
#include "Step.h"

using std::vector;

int Diference(Point& a, Point&b);
bool MoveEnemy(Sprite& target, Sprite& curObject);
bool LookingForNextStep(Sprite& target, Sprite& curObject, Point &newPoint);
vector <Point> FindNeighbors(Sprite& obj);
bool isCollusion(Point& obj1, int obj1W, int obj1H, Point& obj2, int obj2W, int obj2H);

int Diference(Point& a, Point&b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool MoveEnemy(Sprite& target, Sprite& curObject)
{
	Point newStep;
	if (LookingForNextStep(target, curObject, newStep))
	{
		curObject.SetCurPosition(newStep);
		return true;
	}
	else
		return false;
};

//return true if we can move? return false if one of the nearest neighbors is avatar (game over)
bool LookingForNextStep(Sprite& target, Sprite& curObject, Point &newPoint)
{
	//1. lookign nearest neighbors
	bool isAvatarNeer = false;
	vector <Point> vNeighbors = FindNeighbors(curObject);


	Point targetPoint = target.GetCurPosition();
	int targetW = 0, targetH = 0;
	Sprite *pSprite = &target;
	getSpriteSize(pSprite, targetW, targetH);

	int objW = 0, objH = 0;
	pSprite = &curObject;
	getSpriteSize(pSprite, objW, objH);

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



vector <Point> FindNeighbors(Sprite& obj)
{
	vector <Point> vNeighbors;
	Point tempP, enemyPoint = obj.GetCurPosition();
	int wObj = 0, hObj = 0;
	Sprite *pSprite = &obj;
	getSpriteSize(pSprite, wObj, hObj);

	//lookin all neighbors: from top-left to left
	vector <int> forX = { -wObj, 0, wObj, wObj, wObj, 0, -wObj, -wObj };
	vector <int> forY = { -hObj, -hObj, -hObj, 0, hObj, hObj, hObj, 0 };

	int wScreen = 0, hScreen = 0;
	getScreenSize(wScreen, hScreen);

	int n = forX.size();
	for (int i = 0; i < n; ++i)
	{
		tempP = enemyPoint;
		if (enemyPoint.x + forX[i] >= 0 && enemyPoint.x + forX[i] <= wScreen)
			tempP.x = enemyPoint.x + forX[i];

		if (enemyPoint.y + forY[i] >= 0 && enemyPoint.y + forY[i] <= hScreen)
			tempP.y = enemyPoint.y + forY[i];
		vNeighbors.push_back(tempP);
	}

	return(move(vNeighbors));
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