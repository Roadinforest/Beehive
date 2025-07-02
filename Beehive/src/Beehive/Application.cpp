#include "bhpch.h"
#include "Application.h"

#include "Beehive/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace Beehive
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}

		//WindowResizeEvent e(1280, 720);
		//if (e.IsInCategory(EventCategoryApplication))
		//{
		//	BH_TRACE(e.ToString());
		//}
		//if (e.IsInCategory(EventCategoryInput))
		//{
		//	BH_TRACE(e.ToString());
		//}

		//while (true);
		//while (1);
	}
}
