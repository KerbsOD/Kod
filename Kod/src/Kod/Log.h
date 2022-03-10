#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Kod {

	class KOD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		
	};
}

// Core Logs
#define KOD_CORE_ERROR(...)   ::Kod::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KOD_CORE_WARN(...)    ::Kod::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KOD_CORE_INFO(...)    ::Kod::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KOD_CORE_TRACE(...)   ::Kod::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KOD_CORE_FATAL(...)   ::Kod::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Logs
#define KOD_CLIENT_ERROR(...) ::Kod::Log::GetClientLogger()->error(__VA_ARGS__)
#define KOD_CLIENT_WARN(...)  ::Kod::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KOD_CLIENT_INFO(...)  ::Kod::Log::GetClientLogger()->info(__VA_ARGS__)
#define KOD_CLIENT_TRACE(...) ::Kod::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KOD_CLIENT_FATAL(...) ::Kod::Log::GetClientLogger()->fatal(__VA_ARGS__)
