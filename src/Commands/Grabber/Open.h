#ifndef Open_H
#define Open_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Open: public CommandBase
{
public:
	Open();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
