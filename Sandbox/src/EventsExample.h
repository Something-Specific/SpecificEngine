#pragma once

#include "Gin.h"
#include "Events/EventManager.h"
#include <functional>

class EventsExample {
public:
	int Instance;
	EventsExample(int i) {
		Instance = i;
	}
	void ExampleFunc(int a, int b) {
		GAME_TRACE("Instance {0}: arg a {1}, arg b {2}.", Instance, a, b);
	}
};

//Not super elegant but it gets the job done for now in a fairly efficient way. From what I understand there is 
//hardly any overhead for the std::function objects and utilizations
void TestEventsExample() {
	//Example of using the event manager.
	auto t = new EventsExample(666);
	auto el = new Gin::Events::EventManager();

	//First a reference to the function, second a reference to the instance of the class that will handle the function
	//And third two place holders to allocate args for the function callback (placeholders require std::placeholders).
	using namespace std::placeholders;
	std::function<void(int, int)> func = std::bind(&EventsExample::ExampleFunc, t, _1, _2);

	//Next register the func with the EventManager
	el->RegisterKeyboardEvent(func);

	//Finally call this to invoke all registered listeners.
	el->InvokeKeyboardEvent(1, 2);
}