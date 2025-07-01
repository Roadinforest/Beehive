#include "Log.h"

namespace Beehive
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		//spdlog::set_pattern("%^[%T] %n-%l: %v%$"); //The Hazel Version
		spdlog::set_pattern("%^%n-%-8l [%T]: %v%$");
		//https://github.com/gabime/spdlog/wiki/Custom-formatting
		//spdlog::set_pattern("*** [%H:%M:%S %z] [thread %t] %v ***");

		Log::s_CoreLogger = spdlog::stdout_color_mt("Core");
		s_CoreLogger->set_level(spdlog::level::trace);

		Log::s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	void Log::example()
	{
		spdlog::info("Welcome to spdlog!");
		spdlog::error("Some error message with arg: {}", 1);

		spdlog::warn("Easy padding in numbers like {:08d}", 12);
		spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
		spdlog::info("Support for floats {:03.2f}", 1.23456);
		spdlog::info("Positional args are {1} {0}..", "too", "supported");
		spdlog::info("{:<30}", "left aligned");

		spdlog::set_level(spdlog::level::debug); // Set global log level to debug
		spdlog::debug("This message should be displayed..");

		// change log pattern
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

		// Compile time log levels
		// Note that this does not change the current log level, it will only
		// remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
		SPDLOG_TRACE("Some trace message with param {}", 42);
		SPDLOG_DEBUG("Some debug message");
	}
}
