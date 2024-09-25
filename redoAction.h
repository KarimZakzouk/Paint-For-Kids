#pragma once
#include "Actions/Action.h"
#include"Figures/CFigure.h"
#include "ApplicationManager.h"

class redoAction :
    public Action
{private:
public:
    redoAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Record();
    virtual void Play(fstream& Play);


};

