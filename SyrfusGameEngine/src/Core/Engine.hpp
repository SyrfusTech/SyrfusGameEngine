#ifndef ENGINE_GUARD
#define ENGINE_GUARD

#include "Core/Application.hpp"
#include "DataStructures/IterableStack.hpp"

namespace SyrfusGameEngine
{
	class Engine
	{
	public:
		static int Init(Application& app);
		static int Shutdown();

		static int Run();
		static int Stop();

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