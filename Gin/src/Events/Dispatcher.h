#pragma once

#include <vector>
#include <utility>

class Dispatcher {
	template<class C, void(C::*M)() = C::receive>
	static void invoke(void *instance) {
		(static_cast<C*>(instance)->*M)();
	}

public:
	template<class C, void(C::*M)() = &C::receive>
	void bind(C *instance) {
		auto pair = std::make_pair(&invoke<C, M>, instance);
		targets.push_back(pair);
	}

	void operator()() {
		for (auto pair : targets) {
			(pair.first)(pair.second);
		}
	}

private:
	using Fn = void(*)(void *);
	std::vector<std::pair<Fn, void*>> targets;
};