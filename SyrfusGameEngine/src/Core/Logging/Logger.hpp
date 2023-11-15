#ifndef LOGGER_GUARD
#define LOGGER_GUARD

#if SYRFUS_GAME_ENGINE_LOGGING
#include <cstdint>

#define SYRFUS_LOG(logLvl, fmt, ...) Logger::Log(logLvl, fmt, __VA_ARGS__)

#define LOG_LEVEL_FATAL 0b10000000
#define LOG_LEVEL_ERROR 0b01000000
#define LOG_LEVEL_WARN 0b00100000
#define LOG_LEVEL_INFO 0b00010000
#define LOG_LEVEL_DEBUG 0b00001000
#define LOG_LEVEL_TRACE 0b00000100
#define LOG_LEVEL_NONE 0b00000000
#define LOG_LEVEL_ALL 0b11111111

namespace SyrfusGameEngine
{
	class Logger
	{
	public:
		static void Init(uint8_t logLevelMask = LOG_LEVEL_ALL);
		static void Shutdown();

		static void Log(uint8_t logLevel, const char* format, ...);

	private:
		Logger(uint8_t logLevelMask);
		~Logger() = default;
		Logger(const Logger& other) = delete;
		Logger& operator=(const Logger& other) = delete;
		Logger(Logger&&) = delete;
		Logger& operator=(Logger&&) = delete;

	private:
		static Logger* s_Logger;
		uint8_t m_LogLevelMask = 0;
	};
}
#endif

#endif