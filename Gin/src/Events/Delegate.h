#pragma once

#include "..\GinPch.h"

namespace Events {
	class Delegate
	{
		typedef void* InstancePtr;
		typedef void(*InternalFunction)(InstancePtr, int);
		typedef std::pair<InstancePtr, InternalFunction> Stub;

		// turns a free function into our internal function stub
		template <void(*Function)(int)>
		static inline void FunctionStub(InstancePtr, int ARG0)
		{
			// we don't need the instance pointer because we're dealing with free functions
			return (Function)(ARG0);
		}

		// turns a member function into our internal function stub
		template <class C, void (C::*Function)(int)>
		static inline void ClassMethodStub(InstancePtr instance, int ARG0)
		{
			// cast the instance pointer back into the original class instance
			return (static_cast<C*>(instance)->*Function)(ARG0);
		}

	public:
		Delegate(void)
			: m_stub(nullptr, nullptr)
		{
		}

		/// Binds a free function
		template <void(*Function)(int)>
		void Bind(void)
		{
			m_stub.first = nullptr;
			m_stub.second = &FunctionStub<Function>;
		}

		/// Binds a class method
		template <class C, void (C::*Function)(int)>
		void Bind(C* instance)
		{
			m_stub.first = instance;
			m_stub.second = &ClassMethodStub<C, Function>;
		}

		/// Invokes the delegate
		void Invoke(int ARG0) const
		{
			CORE_ASSERT(m_stub.second != nullptr, "Cannot invoke unbound delegate. Call Bind() first.");
			return m_stub.second(m_stub.first, ARG0);
		}

	private:
		Stub m_stub;
	};
}