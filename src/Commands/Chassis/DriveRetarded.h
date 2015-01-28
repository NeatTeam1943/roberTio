#ifndef DriveRetarded_H
#define DriveRetarded_H

#include "../../CommandBase.h"
#include "WPILib.h"


class DriveRetarded: public CommandBase
{
private:
	Joystick* stick;
public:
	DriveRetarded(Joystick* stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();


};

#endif
