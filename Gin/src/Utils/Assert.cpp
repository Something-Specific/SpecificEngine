
#include "..\GinPch.h"

#include "Assert.h"

namespace Gin {
	namespace Util {

		void Assert::CoreAssert(bool condition, const char* failMsg) {
			if (!condition) {
				if(!failMsg) {
					CORE_CRITICAL("Core assertion failed, going down.");
				} else {
					CORE_CRITICAL("Core assertion failure message, {0}", failMsg);
				}
				exit(EXIT_FAILURE);
			}
		}
		void Assert::GameAssert(bool condition, const char* failMsg) {
			if (!condition) {
				if(!failMsg) {
					GAME_CRITICAL("Core assertion failed, going down.");
				} else {
					GAME_CRITICAL("Core assertion failure message, {0}", failMsg);
				}
				exit(EXIT_FAILURE);
			}
		}

	}
}