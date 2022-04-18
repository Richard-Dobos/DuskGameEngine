#pragma once

#include"Dusk/Window.h"

#include"GLFW/glfw3.h"

namespace Dusk
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& WindowProperties);

		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetHeight() const override { return m_WindowsWindowProperties.Height; }
		inline unsigned int GetWidth() const override { return m_WindowsWindowProperties.Width; }

		//Window attributes
		inline void SetEventCallback(const EventCallbackFunc& callback) override { m_WindowsWindowProperties.EventCallback = callback; }
		void SetVsync(bool enabled) override;
		bool isVsync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; };
	private:
		virtual void Init(const WindowProperties& WindowProperties);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowsWindowProperties
		{
			std::string Title;
			unsigned int Height, Width;
			bool Vsync;

			EventCallbackFunc EventCallback;
		};

		WindowsWindowProperties m_WindowsWindowProperties;
	};
}