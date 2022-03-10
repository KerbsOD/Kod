#pragma once

#ifdef KOD_PLATFORM_WINDOWS
	
	extern Kod::Application* Kod::CreateApplication();

	int main(int argc, char** argv)
	{	
		Kod::Log::Init();
		KOD_CORE_WARN("Log initialized");
		KOD_CLIENT_INFO("Salutee");

		auto app = Kod::CreateApplication();
		app->Run();
		delete app;
	}

#endif  

