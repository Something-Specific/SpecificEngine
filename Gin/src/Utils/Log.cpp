
#include "..\GinPch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Gin
{

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::gameLogger;

	void Log::Init() 
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		coreLogger = spdlog::stdout_color_mt("Gin");
		coreLogger->set_level(spdlog::level::trace);

		gameLogger = spdlog::stdout_color_mt("Game");
		gameLogger->set_level(spdlog::level::trace);

	}
}


