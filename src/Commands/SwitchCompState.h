#ifndef SwitchCompState_H
#define SwitchCompState_H

#include "../CommandBase.h"
#include "WPILib.h"

class SwitchCompState: public CommandBase
{
public:
	SwitchCompState();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
