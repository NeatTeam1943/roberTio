#ifndef ReturnToCameraPosition_H
#define ReturnToCameraPosition_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ReturnToCameraPosition: public CommandBase
{
public:
	ReturnToCameraPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
