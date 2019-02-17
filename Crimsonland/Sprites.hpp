#pragma once
#include "Framework.h"
#include <math.h>
#include <vector>

using std::vector;
using std::move;

struct Point
{
	int x;
	int y;

	Point(int m_x = 0, int m_y = 0) : x(m_x), y(m_y) {};
};


bool MoveEnemy(Sprite& target, Sprite& curObject);
bool LookingForNextStep(Sprite& target, Sprite& curObject, Point &newPoint);
vector <Point> FindNeighbors(Sprite& obj);
bool isCollusion(Point& obj1, int obj1W, int obj1H, Point& obj2, int obj2W, int obj2H);


class Sprite
{
protected:
	Point curPosition;
	Point curCenter;

public:
	virtual void Init()
	{
		curPosition.x = 0;
		curPosition.y = 0;
	}
	Point GetCurPosition() const { return curPosition; }
	int GetX() const { return curPosition.x; }
	int GetY() const { return curPosition.y; }
	void SetCurPosition(Point& newPosition)
	{
		curPosition = newPosition;
		curCenter.x = newPosition.x / 2;
		curCenter.y = newPosition.y / 2;
	}

	void SetX(int x) { curPosition.x = x; } //add checking for screenSize
	void SetY(int y) { curPosition.y = y; } //add cheking for screenSize

};


class Avatar: public Sprite
{
public:
	void AvatarInit()
	{
		int x = 0, y = 0;
		getScreenSize(x, y);
		curPosition.x = x/2;
		curPosition.y = y/2;
	}
	friend bool MoveEnemy(Sprite& target, Sprite& curObject);

};

class Enemy : public Sprite
{
	friend bool MoveEnemy(Sprite& target, Sprite& curObject);
};

//function for looking the next step for enemy
//return true if enemy has variatn to move, return false if enemy kill the player
//
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

int Diference(Point& a, Point&b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}


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
	for (int i = 0; i<vNeighbors.size(); ++i)
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