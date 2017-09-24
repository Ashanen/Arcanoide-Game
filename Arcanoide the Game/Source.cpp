#include "About.h"
#include "Arcanoide.h"
#include "Starter.h"

using namespace ArcanoidetheGame;
void CloseWindow(Object^ sender, FormClosedEventArgs^ e) {
	if (Application::OpenForms->Count == 0) {
		Application::Exit();
	}
	else
	{
		Application::OpenForms[0]->FormClosed += gcnew FormClosedEventHandler(CloseWindow);
	}
}



[STAThreadAttribute]

int main(array<String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Starter^ first = gcnew Starter();
	first->FormClosed += gcnew FormClosedEventHandler(CloseWindow);
	first->Show();
	Application::Run();
	return 0;
}