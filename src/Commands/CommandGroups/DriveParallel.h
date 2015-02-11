#ifndef Drive_H
#define Drive_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class DriveParallel: public CommandGroup
{
private:
	Joystick *stick;

public:
	DriveParallel(Joystick *stick);
};

#endif
