#include"dkpch.h"
#include"WindowsWindow.h"

#include"Dusk/Events/ApplicationEvent.h"
#include"Dusk/Events/KeyEvent.h"
#include"Dusk/Events/MouseEvent.h"

namespace Dusk
{
	static bool s_GLFWInitilized = false;

	static void GLFWErorrCallback(int error, const char* description)
	{
		DK_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErorrCallback);
			s_GLFWInitilized = true;
		}

		m_Window = glfwCreateWindow((int)windowProperties.Width, (int)windowProperties.Height, windowProperties.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowsWindowProperties);
		SetVsync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowsWindowProperties& windowProperties = *(WindowsWindowProperties*)glfwGetWindowUserPointer(window);
			WindowResizeEvent event(width, height);

			windowProperties.Width = width;
			windowProperties.Height = height;

			windowProperties.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowsWindowProperties& windowProperties = *(WindowsWindowProperties*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			
			windowProperties.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowsWindowProperties& windowProperties = *(WindowsWindowProperties*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					windowProperties.EventCallback(event);

					break;
				}

				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					windowProperties.EventCallback(event);

					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					windowProperties.EventCallback(event);

					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowsWindowProperties& windowProperties = *(WindowsWindowProperties*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					windowProperties.EventCallback(event);
					break;
				}

			case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					windowProperties.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowsWindowProperties& windowProperties = *(WindowsWindowProperties*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			windowProperties.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
		{
				WindowsWindowProperties& windowProperties = *(WindowsWindowProperties*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)x, (float)y);
				windowProperties.EventCallback(event);
		});
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