#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <chrono>
#include <thread>

#include "Gin.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	Gin::Log::Init();

	Gin::Core::MasterGame* game = new Demo::Game();

	// test->AddEventListener(DemoEvent::DemoEvent::eventType, printTheThing);

	using namespace std::chrono_literals;
	// Make the thread sleep before doing the event. Not async yet
	std::this_thread::sleep_for(1s);

	game->Run();

	return 0;
}
