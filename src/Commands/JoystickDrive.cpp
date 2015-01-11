#include "JoystickDrive.h"

JoystickDrive::JoystickDrive(Joystick* stick) {
	Requires(chassis);
	this->stick = stick;
}

void JoystickDrive::Initialize() {

}

void JoystickDrive::Execute() {
	chassis->ChassisJoystick(stick);
}

bool JoystickDrive::IsFinished() {
	return false;
}

void JoystickDrive::End() {

}

void JoystickDrive::Interrupted() {
	End();
}
