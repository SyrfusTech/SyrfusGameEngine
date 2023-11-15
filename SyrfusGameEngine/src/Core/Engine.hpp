#ifndef ENGINE_GUARD
#define ENGINE_GUARD

#include "Core/Application.hpp"
#include "DataStructures/IterableStack.hpp"

namespace SyrfusGameEngine
{
	class Engine
	{
	public:
		static void Init(Application& app);
		static void Shutdown();

		static void Run();
		static void Stop();

	private:
		Engine() = default;
		~Engine() = default;
		Engine(const Engine& other) = delete;
		Engine& operator=(const Engine& other) = delete;
		Engine(Engine&&) = delete;
		Engine& operator=(Engine&&) = delete;

	private:
		static Engine* s_Instance;
		bool m_Running = false;
		IterableStack<Application*> m_AppStack;
	};
}

#endif