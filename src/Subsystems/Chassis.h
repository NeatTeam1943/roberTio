#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	RobotDrive *drive;
public:
	Chassis();
	void InitDefaultCommand();
	void Drive(float x, float y);
	void ChassisJoystick(Joystick *stick);
};

#endif
