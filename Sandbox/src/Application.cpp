
#include "Gin.h"
#include "Game.h"
#include "EventsExample.h"
#include "../DemoEvent.cpp"
#include <chrono>
#include <thread>

void printTheThing(const Gin::Events::Event& event) {
	printf("Hurray! The event was received!\n");
}

int main(int argc, char *argv[])
{
	Gin::Log::Init();
	
	Gin::Core::MasterGame* game = new Demo::Game();
	Gin::Display::Actor* test = new Gin::Display::Actor();

	test->AddEventListener(DemoEvent::DemoEvent::eventType, printTheThing);

	using namespace std::chrono_literals;
	// Make the thread sleep before doing the event. Not async yet
	std::this_thread::sleep_for(1s);
	test->DispatchEvent(DemoEvent::DemoEvent());

	game->Run();


	return 0;
}
