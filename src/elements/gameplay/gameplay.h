#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "raylib.h"
namespace worm_painters
{
	class Gameplay
	{
	public:
		Gameplay();
		~Gameplay();
		void Restart();
		void Input();
		void Update();
		void Draw();
	private:
		float timeGameplayScale = 1.0f;
	};
}
#endif