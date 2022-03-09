#include "Kod.h"

class Sandbox : public Kod::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{
		 
	}
};

Kod::Application* Kod::CreateApplication()
{
	return new Sandbox();
}