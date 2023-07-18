#pragma once

#include"dkpch.h"
#include"Core.h"
#include"Events/Event.h"

namespace Dusk
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Height, Width;

		WindowProperties(const std::string& title = "Dusk Engine", unsigned int width = 1280, unsigned int height = 720)
			:Title(title), Width(width), Height(height){}
	};

	class  Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		
		//Window parametrs
		virtual unsigned int GetHeight() const = 0;
		virtual unsigned int GetWidth() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVsync(bool enable) = 0;
		virtual bool isVsync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& windowProperties = WindowProperties());
	};
}