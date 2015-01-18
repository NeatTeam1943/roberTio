#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Subsystems/Chassis.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Grabber.h"
#include "Subsystems/Camera.h"
#include <string>
#include "OI.h"
#include "WPILib.h"

class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	static Chassis *chassis;
	static Elevator *elevator;
	static Grabber *grabber;
	static Camera *camera;
	static OI *oi;
};

#endif
