#include "bhpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

namespace Beehive
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		// Knowledge!!!
		// In this case the window class has no idea who gives it this function
		// What it knows is that the OnEvent function itself
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		BH_CORE_TRACE("{0}", e.ToString());
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
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

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;        // Return true if normal exectued
	}
}
