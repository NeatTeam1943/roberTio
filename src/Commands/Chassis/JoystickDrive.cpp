#include "JoystickDrive.h"

JoystickDrive::JoystickDrive(Joystick* stick) {
	Requires(chassis);
	this->stick = stick;
}

void JoystickDrive::Initialize() {

}

void JoystickDrive::Execute() {
	if (stick->GetRawAxis(3) > 0.3 && !chassis->GetPhotoSwitch()) {
		chassis->Drive(stick->GetRawAxis(3), 0);
	} else {
		chassis->SetCenterPower(stick->GetRawAxis(4));
		chassis->DriveJoystick(stick);
	}
	/*
	 chassis->DriveCombined(stick);
	 chassis->TurnInPlace(stick);
	 */
}

bool JoystickDrive::IsFinished() {
	return false;
}

void JoystickDrive::End() {

}

void JoystickDrive::Interrupted() {
	End();
}
