
#include "Gin.h"
//#include "Game.h"
//#include "EventsExample.h"
#include <iostream>
#include <nlohmann/json.hpp>


int main(int argc, char *argv[])
{
	nlohmann::json t = {
		  {"pi", 3.141},
		  {"happy", true},
		  {"name", "Niels"},
		  {"nothing", nullptr},
		  {"answer", {
			{"everything", 42}
		  }},
		  {"list", {1, 0, 2}},
		  {"object", {
			{"currency", "USD"},
			{"value", 42.99}
		  }}
	};
	std::cout << t << std::endl;
	return 0;
}