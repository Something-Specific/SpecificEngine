
#include "Gin.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	Gin::Log::Init();
	Gin::Core::MasterGame* game = new Demo::Game();
	game->Run();


	return 0;
}