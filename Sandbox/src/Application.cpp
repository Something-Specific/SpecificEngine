
#include "Gin.h"
#include "Game.h"
#include "EventsExample.h"

int main(int argc, char *argv[])
{
	Gin::Log::Init();
	
	TestEventsExample();
	
	Gin::Core::MasterGame* game = new Demo::Game();
	game->Run();
	
	return 0;
}