#include "Game.h"
int main()
{
	srand((unsigned)time(NULL));
	Game game;
	game.run();
	//while (game.getWindow().isOpen())
	//{
	//	game.update();
	//	game.render();
	//}
	
	return 0;
}