#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\saveAction.h"
#include "Actions\Exit.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;

	FigCount = 0;
	pOut = new Output;
	pIn = pOut->CreateInput();

	//Create an array of figure pointers and set them to NULL
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);

		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();

	}while(ActType != EXIT);

}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType)
{
	Action* newAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;
        case SAVE:
            newAct = new SaveAction(this, FigCount);
            break;


		case DRAW_ELPS:
			///create AddLineAction here

			break;

		case EXIT:
            newAct = new Exit(this);
			break;

		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct)
{
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
string ApplicationManager::ConvertToString(color c)   //Convert from Color Type to String Type
{
	if(c==BLACK) return "BLACK";
	else if(c==WHITE) return "WHITE";
	else if(c==BLUE) return "BLUE";
	else if(c==RED) return "RED";
	else if(c==YELLOW) return "YELLOW";
	else if(c==GREEN) return "GREEN";
	else if(c==LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	else if(c==MAGENTA) return "MAGENTA";
	else if(c==TURQUOISE) return "TURQUOISE";
	return "COLOR";
}

color ApplicationManager::ConvertToColor(string s)
{
	if (s == "BLACK")
		return BLACK;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	if (s == "MAGENTA")
		return MAGENTA;
	if (s == "TURQUOISE")
		return TURQUOISE;
	return BLACK;
}
void ApplicationManager::SaveFig(ofstream &Out)   //Call the Save function for each Figure
{
	//set_selected(NULL);
	//Unselect(NULL);
	for(int i=0; i<FigCount; ++i)
		FigList[i]->Save(Out);
}
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;

}
