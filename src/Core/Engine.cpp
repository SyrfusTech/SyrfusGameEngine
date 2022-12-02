#include "Engine.hpp"
#include <iostream>

namespace SyrfusGameEngine
{
	Engine::Engine()
	{

	}

	Engine::~Engine()
	{
		
	}

	void Engine::run()
	{
		std::cout << "Run from engine" << std::endl;
	}
}