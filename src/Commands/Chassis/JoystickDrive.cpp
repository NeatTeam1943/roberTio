#include "JoystickDrive.h"

JoystickDrive::JoystickDrive(Joystick* stick) {
	Requires(chassis);
	this->stick = stick;
}

void JoystickDrive::Initialize() {

}

void JoystickDrive::Execute() {
	/*if (chassis->GetPhotoSwitch() && oi->GetButtons()[8]->Get())
		Wait(3);
	else {*/
	 chassis->DriveJoystick(stick);
	 chassis->SetCenterPower(stick->GetRawAxis(4));
	 /*}

	else {
		chassis->DriveCombined(this->stick);
		chassis->TurnInPlace(this->stick->GetRawAxis(4));
	}*/
}

bool JoystickDrive::IsFinished() {
	return false;
}

void JoystickDrive::End() {

}

void JoystickDrive::Interrupted() {
	End();
}
