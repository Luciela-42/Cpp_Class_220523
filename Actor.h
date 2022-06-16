#pragma once
#include <string>
#include "SpriteType.h"
#include "SDL.h"

using namespace std;

//2차원 좌표에 자신을 렌더링하고 충돌하고 처리한다.
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape, bool bNewCollision = false, int NewSortOrder = 1);
	virtual ~AActor();

	//ESpriteType Type;
	char Shape;
	int X;
	int Y;
	bool bCollision;
	int SortOrder;

	int R = 0;
	int G = 0;
	int B = 0;
	int A = 255;

	SDL_Color ColorKey;

	void LoadBMP(string Filename);

	SDL_Surface* MySurface = nullptr;
	SDL_Texture* MyTexture = nullptr;

	int Size = 60;

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	static bool compare(AActor* First, AActor* Second)
	{
		return First->SortOrder < Second->SortOrder;
	}

	bool PredictCollision(int PredictX, int PredictY);


};
