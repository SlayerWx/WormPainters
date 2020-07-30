#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "raylib.h"
#include "elements/map/map.h"
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
		Map* map;
	private:
		float timeGameplayScale = 1.0f;
	};
}
#endif