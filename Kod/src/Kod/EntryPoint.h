#pragma once

#ifdef KOD_PLATFORM_WINDOWS
	
extern Kod::Application* Kod::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Kod::CreateApplication();
	app->Run();
	delete app;
}
#endif  

