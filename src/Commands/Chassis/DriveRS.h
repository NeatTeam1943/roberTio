#ifndef DriveRS_H
#define DriveRS_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveRS: public CommandBase
{
private:
	Joystick *stick;

public:
	DriveRS(Joystick *stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
