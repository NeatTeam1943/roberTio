#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include "Xbox/Xbox360.h"

class OI
{
private:
	Xbox360 *stick;
public:
	OI();
	Xbox360* getJoystick();
};

#endif
