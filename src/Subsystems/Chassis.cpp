#include "Chassis.h"
#include "../Commands/DriveWithJoystick.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

Chassis::Chassis() :
		Subsystem("Chassis") {

}

void Chassis::InitDefaultCommand() {
	this->SetDefaultCommand(new DriveWithJoystick(CommandBase::oi->getJoystick()));
}

void Chassis::Drive(float x, float y) {
	drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveWithJoystick(Joystick *stick) {
	drive->ArcadeDrive(stick, false);
}
