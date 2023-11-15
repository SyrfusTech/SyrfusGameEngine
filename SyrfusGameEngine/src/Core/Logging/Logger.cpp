#include "Logger.hpp"

#include <iostream>
#include <chrono>

namespace SyrfusGameEngine
{
	Logger* Logger::s_Logger = nullptr;

	void Logger::Init(uint8_t logLevelMask)
	{
		if (s_Logger)
			return;
		s_Logger = new Logger(logLevelMask);
	}

	void Logger::Shutdown()
	{
		if (!s_Logger)
			return;
		delete s_Logger;
	}


	void Logger::Log(uint8_t logLevel, const char* format, ...)
	{
		if (!(logLevel & s_Logger->m_LogLevelMask))
			return;

	}

	Logger::Logger(uint8_t logLevelMask) : m_LogLevelMask(logLevelMask) {}

}