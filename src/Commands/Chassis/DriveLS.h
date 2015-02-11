#ifndef DriveLS_H
#define DriveLS_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveLS: public CommandBase
{
private:
	Joystick *stick;

public:
	DriveLS(Joystick *stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
