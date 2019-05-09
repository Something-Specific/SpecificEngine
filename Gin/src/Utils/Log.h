#pragma once


#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Gin
{
	class Log
	{
	public:
		static void Init();

		// For multiple args, use {} as a placeholder in the first arg and the remaining args are placed inside.
		// Example CORE_INFO("This is a {}", "test") outputs: "This is a test"
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return gameLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> gameLogger;

	};
}
