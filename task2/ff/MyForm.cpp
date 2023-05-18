#include "pch.h"
#include "MyForm.h"
#include<iostream>
#include<String>
#include<map>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ff::MyForm());
	system("pause");
}

