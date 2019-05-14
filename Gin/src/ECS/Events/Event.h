#pragma once

#include <functional>
#include <stdio.h>

namespace Gin {
	namespace ECS {

		using namespace std;
		using namespace placeholders;
		template <typename T>
		class Event
		{
		public:
			void Register(function<void(T*)> func);
			void Invoke(T);
		};
	}
}