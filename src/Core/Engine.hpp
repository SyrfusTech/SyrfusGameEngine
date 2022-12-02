#ifndef ENGINE_GUARD
#define ENGINE_GUARD

#include "Core/Application.hpp"

namespace SyrfusGameEngine
{
	class Engine
	{
	public:
		static int init(Application& app);
		static int shutdown();

		static int run();
		static int stop();

	private:
		Engine();
		Engine(const Engine& other) = delete;
		Engine& operator=(const Engine& other) = delete;

		~Engine();

	private:
		static Engine* s_Instance;
		bool m_Running = false;
		Application* m_App;

	};
}

#endif