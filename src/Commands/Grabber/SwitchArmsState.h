#ifndef SwitchArmsState_H
#define SwitchArmsState_H

#include "../CommandBase.h"
#include "WPILib.h"

class SwitchArmsState: public CommandBase
{
private:
	bool isToOpen;

public:
	SwitchArmsState();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
