
#include "Demo\Game.h"
#include "Core\MasterGame.h"
#include "Core\Debug\Log.h"

void main(int argc, char *argv[])
{
	Core::Log::Init();
	CORE_TRACE("trace");
	CORE_INFO("info");
	CORE_WARN("warn");
	CORE_ERROR("error");
	GAME_CRITICAL("fatal");
	
	//Creates the game object
	Demo::Game game = Demo::Game();

	//Casts it to a mastergame for the run function
	Core::MasterGame *mGame = &game;

	//Calls run which will begin by initializing the game
	mGame->Run();
	

}