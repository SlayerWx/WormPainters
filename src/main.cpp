#include "worm_painters/worm_painters.h"
using namespace worm_painters;
int main()
{
	WormPainters* game = new WormPainters();
	game->Play();
	if (game) delete game;
	return 0;
}