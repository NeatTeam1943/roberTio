#ifndef Close_H
#define Close_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Close: public CommandBase
{
public:
	Close();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
