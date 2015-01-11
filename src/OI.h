#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"

class OI
{
private:
	Joystick *stick;
public:
	OI();
	Joystick* getJoystick();
};

#endif
