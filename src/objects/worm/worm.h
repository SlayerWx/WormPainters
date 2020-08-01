#ifndef OBJECT_H
#define OBJECT_H
#include "raylib.h"
namespace worm_painters
{
enum BodyPart
{
	head = 0,next
};
class Worm
{
public:
	Worm(float width, float height, Color color, Texture2D texture);
	~Worm();
	void myRestart(float x, float y, float width, float height);
	void SetX(float newX);
	float GetX();
	void SetY(float newY);
	float GetY();
	void SetPosition(float x, float y);
	Vector2 GetPosition();
	void SetHeightAndWidth(float height, float width);
	void SetHeight(float height);
	float GetHeight();
	void SetWidth(float width);
	float GetWidth();
	void SetColor(Color color);
	Color GetColor();
	void changeShow(bool chng);
	bool getShow();
	void SetNewPos(float nextX, float nextY);
	void Update(float timer);
	void Lerp(float timer);
	void Draw();
	Rectangle GetBody();
	void SetActive(bool ctive);
	bool GetActive();
private:
	Color myColor = GRAY;
	Rectangle body;
	Vector2 startPosition;
	Vector2 endPosition;
	bool imShowing = true;
	Texture2D myTexture;
	int centrerTextureInCubeModif = 4;
	bool imActive;
};
}
#endif 