#include"dkpch.h"
#include"WindowsWindow.h"

namespace Dusk
{
	static bool s_GLFWInitilized = false;

	Window* Window::Create(const WindowProperties& windowProperties)
	{
		return new WindowsWindow(windowProperties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& windowProperties)
	{
		Init(windowProperties);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProperties& windowProperties)
	{
		m_WindowsWindowProperties.Height = windowProperties.Height;
		m_WindowsWindowProperties.Width = windowProperties.Width;
		m_WindowsWindowProperties.Title = windowProperties.Title;

		DK_CORE_INFO("Window Created: {0} [ {1}, {2} ]", windowProperties.Title, windowProperties.Width, windowProperties.Height);

		if (!s_GLFWInitilized)
		{
			int succes = glfwInit();
			
			//TODO: Define assert macro for glfwInit()

			s_GLFWInitilized = true;
		}

		m_Window = glfwCreateWindow((int)windowProperties.Width, (int)windowProperties.Height, windowProperties.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowsWindowProperties);
		SetVsync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVsync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);

		else
			glfwSwapInterval(0);

		m_WindowsWindowProperties.Vsync = enabled;
	}

	bool WindowsWindow::isVsync() const
	{
		return m_WindowsWindowProperties.Vsync;
	}
}