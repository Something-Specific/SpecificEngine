
#include "..\GinPch.h"

#include "Assert.h"

namespace Gin {
	namespace Debug {

		void Assert::CoreAssert(bool condition, const char* failMsg) {
			if (!condition) {
				CORE_CRITICAL("Core assertion failed, going down.");
				CORE_CRITICAL("Core assertion failure message, {0}", failMsg);
				exit(EXIT_FAILURE);
			}
		}
		void Assert::GameAssert(bool condition, const char* failMsg) {
			if (!condition) {
				GAME_CRITICAL("Core assertion failed, going down.");
				GAME_CRITICAL("Core assertion failure message, {0}", failMsg);
				exit(EXIT_FAILURE);
			}
		}

	}
}