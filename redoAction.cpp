#include "redoAction.h"
#include<fstream>
redoAction::redoAction(ApplicationManager* pApp):Action(pApp)
{
}

void redoAction::ReadActionParameters()
{
}

void redoAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	if (pManager->getRedoCnt())
	{
		pManager->RedoAct();
		pOut->PrintMessage("Redo");
		pOut->ClearDrawArea();
		pManager->setRedoCnt(pManager->getRedoCnt()-1);
	}
	else
	{
		pOut->PrintMessage("No actions to be Redone");
	}
	if (pManager->GetIsRecording() && operationCount < MaxRecOperaion)
		Record();
}

void redoAction::Record()
{
	operationCount++;
	fstream Rec(recordFile, ios::app);
	Rec << "\t" << "Redo" << endl;              
	Rec.close();
		
	
}

void redoAction::Play(fstream& Play)
{
	Execute();

}
