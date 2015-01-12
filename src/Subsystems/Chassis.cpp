#include <Commands/JoystickDrive.h>
#include "Chassis.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

Chassis::Chassis() :
	Subsystem("Chassis") {
	this->drive = new RobotDrive(RIGHT_MOTOR, LEFT_MOTOR);
}

void Chassis::InitDefaultCommand() {
	this->SetDefaultCommand(new JoystickDrive(CommandBase::oi->getJoystick()));
}

void Chassis::Drive(float x, float y) {
	drive->ArcadeDrive(y, x, false);
}

void Chassis::ChassisJoystick(Joystick *stick) {
	drive->ArcadeDrive(stick, false);
}
