#pragma once
#include "Actions/Action.h"
#include"Figures/CFigure.h"
#include "ApplicationManager.h"
class undoAction : public Action
{
private:
    Action* pAct;

public:
    undoAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();
    virtual void Record();

    virtual void Play(fstream& Play);


};

