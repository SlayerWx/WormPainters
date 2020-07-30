#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "raylib.h"
#include "elements/map/map.h"
#include "objects/player/player.h"
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
		static const int maxPlayers = 4;
		Player* p[maxPlayers];
	private:
		float timeGameplayScale = 0.5f;
		void CheckCollision();
	};
}
#endif