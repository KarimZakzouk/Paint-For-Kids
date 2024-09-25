#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <fstream>
#include "..\DefS.h"

class ApplicationManager; // Forward class declaration

// Base class for all possible actions
class Action
{
protected:
    ApplicationManager* pManager;  // Actions need AppMngr to do their job
    bool isFilled;
    static int operationCount; // Declaration of the static member
    std::string recordFile;
    const int MaxRecOperation;

public:
    Action(ApplicationManager* pApp)
        : pManager(pApp), isFilled(false), MaxRecOperation(20), recordFile("Record/Record.txt") {} // Constructor

    // Reads parameters required for action to execute (code depends on action type)
    virtual void ReadActionParameters() = 0;

    // Execute action (code depends on action type)
    virtual void Execute() = 0;
    virtual void UndoAction() {};
    virtual void RedoAction() {};
    virtual void Record() {}; // Cannot be pure virtual because there are some actions that cannot be recorded
    virtual void Play(std::fstream& Play) {}; // Cannot be pure virtual because there are some actions that cannot be recorded
};

#endif // ACTION_H
