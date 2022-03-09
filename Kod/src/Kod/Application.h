#pragma once

#include "Core.h";


namespace Kod {

	class KOD_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	// Define in Client.
	Application* CreateApplication();
}

