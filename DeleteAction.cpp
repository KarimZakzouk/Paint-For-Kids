#include "DeleteAction.h"
#include<fstream>

DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp), SelectedFig(NULL)
{
}

void DeleteAction::ReadActionParameters()
{
}

void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	SelectedFig=pManager->GetLastSelected();
	if (SelectedFig)
	{
		pManager->DeleteSelectedFig(SelectedFig);

		pManager->AddActToUndoRedo(this);
		pManager->setWillBeDeleted(true);
		pManager->ResetRedoCnt();

		pOut->ClearDrawArea();
		pOut->PrintMessage("Delete Selected Figure");
	}
	else
		pOut->PrintMessage("No Selected Figure");
}

void DeleteAction::UndoAction()
{
	if (SelectedFig != NULL)
	{
		pManager->AddFigure(SelectedFig);
		SelectedFig->SetSelected(false);
	}
}

void DeleteAction::RedoAction()
{
	Output* pOut = pManager->GetOutput();
	if (SelectedFig != NULL)
	{
		pManager->DeleteSelectedFig(SelectedFig);
	}
	SelectedFig = pManager->GetLastSelected();
	if (SelectedFig)
	{
		pManager->DeleteSelectedFig(SelectedFig);
		pOut->ClearDrawArea();
		pOut->PrintMessage("Delete Selected Figure");
		if(!pManager->isMuted())
			PlaySound("sounds/delete_effect", NULL, SND_ASYNC);
	}
	else
		pOut->PrintMessage("No Selected Figure");
	if (pManager->GetIsRecording() && operationCount < MaxRecOperaion)
		Record();
	
}

void DeleteAction::Record()
{
	operationCount++;
	fstream Rec(recordFile, ios::app);
	Rec << "\t" << "Delete" << endl;             
	Rec.close();
		
	
}

void DeleteAction::Play(fstream& Play)
{
	Execute();
}

