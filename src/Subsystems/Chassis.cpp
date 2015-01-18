#include <Commands/CarJoystickDrive.h>
#include <Commands/JoystickDrive.h>
#include "Chassis.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

Chassis::Chassis() :
		Subsystem("Chassis") {
	this->drive = new RobotDrive(RIGHT_MOTOR, LEFT_MOTOR);
}

void Chassis::InitDefaultCommand() {
//	this->SetDefaultCommand(
//			new CarJoystickDrive(CommandBase::oi->getJoystick()));
	this->SetDefaultCommand(new JoystickDrive(CommandBase::oi->getJoystick()));
}

void Chassis::Drive(float x, float y) {
	drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveJoystick(Joystick *stick) {
	this->drive->ArcadeDrive(stick->GetY(), -stick->GetX(), false);
}

void Chassis::CarDriveJoystick(Joystick *stick) {
	if (stick->GetThrottle() > 0)
		this->drive->ArcadeDrive(-stick->GetThrottle(), -stick->GetX(), false);
	else
		this->drive->ArcadeDrive(stick->GetZ(), -stick->GetX(), false);
}

void Chassis::DriveJoystick2(Joystick *stick) {
	this->drive->ArcadeDrive(stick->GetTwist(), -stick->GetRawAxis(5), false);
}
