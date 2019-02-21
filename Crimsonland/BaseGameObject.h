#pragma once
#include "Framework.h"

class Sprite;

struct Point
{
	int x;
	int y;

	Point(int m_x = 0, int m_y = 0) : x(m_x), y(m_y) {};
};

class GameObject
{
protected:
	Point curPosition;
	//Point curCenter;

public:
	Sprite* sprite;
	GameObject();
	Point GetCurPosition() const;
	int GetX() const;
	int GetY() const; 
	void SetCurPosition(Point& newPosition);
	void SetX(int x); 
	void SetY(int y); 
};