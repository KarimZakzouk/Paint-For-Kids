#include "undoAction.h"
#include<fstream>
undoAction::undoAction(ApplicationManager* pApp):Action(pApp)
{
}

void undoAction::ReadActionParameters()
{
}

void undoAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	if (pManager->getUndoCnt())
	{
		pManager->UndoAct();
		pOut->PrintMessage("Undo");
		pOut->ClearDrawArea();
		pManager->setRedoCnt(pManager->getRedoCnt()+1);
	}
	else
	{
		pOut->PrintMessage("No actions to be Undone");
	}

	if (pManager->GetIsRecording() && operationCount < MaxRecOperaion)
		Record();
}

void undoAction::Record()
{	
	operationCount++;
	fstream Rec(recordFile, ios::app);
	Rec << "\t" << "Undo" << endl;         
	Rec.close();
		
	
}

void undoAction::Play(fstream& Play)
{

	Execute();

}
