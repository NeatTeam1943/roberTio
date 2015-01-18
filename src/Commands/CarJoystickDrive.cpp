#include "CarJoystickDrive.h"

CarJoystickDrive::CarJoystickDrive(Joystick* stick) {
	Requires(chassis);
	this->stick = stick;
}

void CarJoystickDrive::Initialize() {

}

void CarJoystickDrive::Execute() {
	chassis->CarDriveJoystick(stick);
}

bool CarJoystickDrive::IsFinished() {
	return false;
}

void CarJoystickDrive::End() {

}

void CarJoystickDrive::Interrupted() {
	End();
}
