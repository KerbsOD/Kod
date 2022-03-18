#include "kodpch.h"
#include "Application.h"
#include "Kod/Events/ApplicationEvent.h"
#include "Kod/Log.h"

#include <GLFW/glfw3.h>

namespace Kod {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		KOD_CORE_INFO("{0}", e);
	}

	void Application::Run()
	{
		while (m_Running)
		{	
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}