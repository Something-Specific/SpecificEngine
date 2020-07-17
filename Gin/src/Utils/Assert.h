#pragma once


namespace Gin {
	namespace Util {

		class Assert
		{
		public:
			static void CoreAssert(bool condition);
			static void CoreAssert(bool condition, const char* failMsg);
			
			static void GameAssert(bool condition);
			static void GameAssert(bool condition, const char* failMsg);

		};
	}
}

