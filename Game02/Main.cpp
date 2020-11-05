#include "Game.h"
int main()
{
	srand((unsigned)time(NULL));
	Game game;
	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}
	
	return 0;
}