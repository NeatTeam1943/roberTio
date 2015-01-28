#ifndef CarJoystickDrive_H
#define CarJoystickDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class CarJoystickDrive: public CommandBase
{
private:
	Joystick* stick;
public:
	CarJoystickDrive(Joystick* stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
