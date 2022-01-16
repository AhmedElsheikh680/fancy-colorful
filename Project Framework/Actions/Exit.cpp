
#include "Exit.h"
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"SaveAction.h"
Exit::Exit(ApplicationManager *pApp) : Action(pApp)
{}

void Exit::ReadActionParameters()
{}

void Exit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn  =pManager->GetInput();

	pOut->PrintMessage("Sure? You want to save your graph befor exit? if yes then write Y or any key to exit");
	string s = pIn->GetSrting(pOut);
	if(s == "Y" || s == "y")
	{
		ActionType newAct = SAVE;
		pManager->CreateAction(newAct);
	}
	else
	{
		//pManager->set_LastMessage("We will miss you :(");
	}

}
