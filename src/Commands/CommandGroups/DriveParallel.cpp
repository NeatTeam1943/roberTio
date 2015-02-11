#include <Commands/CommandGroups/DriveParallel.h>
#include "../Chassis/DriveLS.h"
#include "../Chassis/DriveRS.h"

DriveParallel::DriveParallel(Joystick *stick)
{
	this->stick = stick;
	AddParallel(new DriveLS(this->stick));
	AddParallel(new DriveRS(this->stick));
}
