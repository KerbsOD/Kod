#pragma once

#include "kodpch.h"
#include "Kod/Core.h"
#include "Kod/Events/Event.h"

namespace Kod {

	struct WindowProps 
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Kod Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), 
			  Width(width), 
			  Height(height)
		{
		}
	};

	class KOD_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
