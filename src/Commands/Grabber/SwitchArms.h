#ifndef SwitchArms_H
#define SwitchArms_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SwitchArms: public CommandBase
{
public:
	SwitchArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
