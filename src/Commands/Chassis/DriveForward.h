#ifndef DriveForwardTimed_H
#define DriveForwardTimed_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveForward: public CommandBase {
private:
	//int runTime;
	float power;

public:
	DriveForward(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
