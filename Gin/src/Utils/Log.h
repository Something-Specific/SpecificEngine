#pragma once


#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Gin
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return gameLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> gameLogger;

	};
}
