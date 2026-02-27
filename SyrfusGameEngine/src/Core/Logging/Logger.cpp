#include "Logger.hpp"

#if SYRFUS_GAME_ENGINE_LOGGING

#include <iostream>
#include <chrono>

#include <cstdarg>

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

		std::string message = format;
		PrepareMessage(logLevel, message);

		va_list args;
		va_start(args, format);
		vprintf(message.c_str(), args);
		va_end(args);
	}

	Logger::Logger(uint8_t logLevelMask) : m_LogLevelMask(logLevelMask) {}

	void Logger::PrepareMessage(uint8_t loglevel, std::string& message)
	{
		// TODO: Format time as yyyy/mm/dd - [00:00:00]
		auto now = std::chrono::system_clock::now();
		std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
		std::tm* timeInfo = std::localtime(&nowTime);
		char timeBuffer[100];
		std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d [%H:%M:%S]: ", timeInfo);
		message = timeBuffer + message + "\n";

		// TODO: Prepend message with log-level / change message color.
		switch (loglevel)
		{
		case LOG_LEVEL_FATAL:
			break;
		case LOG_LEVEL_ERROR:

			break;
		case LOG_LEVEL_WARN:

			break;
		case LOG_LEVEL_INFO:

			break;
		case LOG_LEVEL_DEBUG:

			break;
		case LOG_LEVEL_TRACE:

			break;
		default:

			break;
		}
	}

}

#endif