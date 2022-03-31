#pragma once

#include"Core.h"

#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
#include"spdlog/fmt/ostr.h"


namespace Dusk
{
	class DUSK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macro
#define DK_CORE_INFO(...) ::Dusk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DK_CORE_TRACE(...) ::Dusk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DK_CORE_WARN(...) ::Dusk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DK_CORE_ERROR(...) ::Dusk::Log::GetCoreLogger()->error(__VA_ARGS__)

//App log macro
#define DK_CORE_INFO(...) ::Dusk::Log::GetClientLogger()->info(__VA_ARGS__)
#define DK_CORE_TRACE(...) ::Dusk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DK_CORE_WARN(...) ::Dusk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DK_CORE_ERROR(...) ::Dusk::Log::GetClientLogger()->error(__VA_ARGS__)