#pragma once

#include "Assert.h"
#include "Log.h"

#ifndef DIST //Turn off macro functionality for distribution builds.
#define CORE_TRACE(...)       ::Gin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)        ::Gin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)        ::Gin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)       ::Gin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...)    ::Gin::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define GAME_TRACE(...)       ::Gin::Log::GetGameLogger()->trace(__VA_ARGS__)
#define GAME_INFO(...)        ::Gin::Log::GetGameLogger()->info(__VA_ARGS__)
#define GAME_WARN(...)        ::Gin::Log::GetGameLogger()->warn(__VA_ARGS__)
#define GAME_ERROR(...)       ::Gin::Log::GetGameLogger()->error(__VA_ARGS__)
#define GAME_CRITICAL(...)    ::Gin::Log::GetGameLogger()->critical(__VA_ARGS__)

#define CORE_ASSERT(...)	  ::Gin::Util::Assert::CoreAssert(__VA_ARGS__)
#define GAME_ASSERT(...)	  ::Gin::Util::Assert::GameAssert(__VA_ARGS__)

#else
#define CORE_TRACE(...)
#define CORE_INFO(...) 
#define CORE_WARN(...) 
#define CORE_ERROR(...)
#define CORE_FATAL(...)

#define GAME_TRACE(...)
#define GAME_INFO(...) 
#define GAME_WARN(...) 
#define GAME_ERROR(...)
#define GAME_FATAL(...)

#define CORE_ASSERT(...)
#define GAME_ASSERT(...)
#endif

#define BIT(x) (1 << x)