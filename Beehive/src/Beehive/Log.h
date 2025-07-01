#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

#include <memory>

namespace Beehive
{
	class BH_API Log
	{
	public:
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
		static void Init();
		static void example();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define BH_CORE_ERROR(...) ::Beehive::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BH_CORE_DEBUG(...) ::Beehive::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define BH_CORE_INFO(...) ::Beehive::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BH_CORE_TRACE(...) ::Beehive::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BH_CORE_WARN(...) ::Beehive::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BH_CORE_CRITICAL(...) ::Beehive::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define BH_ERROR(...) ::Beehive::Log::GetClientLogger()->error(__VA_ARGS__)
#define BH_DEBUG(...) ::Beehive::Log::GetClientLogger()->debug(__VA_ARGS__)
#define BH_INFO(...) ::Beehive::Log::GetClientLogger()->info(__VA_ARGS__)
#define BH_TRACE(...) ::Beehive::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BH_WARN(...) ::Beehive::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BH_CRITICAL(...) ::Beehive::Log::GetClientLogger()->critical(__VA_ARGS__)
