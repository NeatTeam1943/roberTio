#ifndef DownSwitchSchnitzel_H
#define DownSwitchSchnitzel_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DownSwitchSchnitzel: public CommandBase
{
public:
	DownSwitchSchnitzel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
