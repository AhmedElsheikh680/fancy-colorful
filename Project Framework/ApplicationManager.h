#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "GUI\UI_Info.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	GUI* pGUI;
	Input *pIn;
	Output *pOut;


public:
	ApplicationManager();
	~ApplicationManager();

	void Run();		//to run the application

	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action

	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
    string ConvertToString(color c);   //Convert from Color Type to String Type
	color ConvertToColor(string s);

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SaveFig(ofstream &Out);

	// -- Interface Management Functions
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window
};

#endif
