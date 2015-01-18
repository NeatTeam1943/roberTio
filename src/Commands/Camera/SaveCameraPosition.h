#ifndef SaveCameraPosition_H
#define SaveCameraPosition_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SaveCameraPosition: public CommandBase
{
public:
	SaveCameraPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
