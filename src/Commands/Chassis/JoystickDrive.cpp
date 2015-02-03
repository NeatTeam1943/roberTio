#include "JoystickDrive.h"

JoystickDrive::JoystickDrive(Joystick* stick) {
	Requires(chassis);
	this->stick = stick;
}

void JoystickDrive::Initialize() {

}

void JoystickDrive::Execute() {
	/*if (-stick->GetRawAxis(3) > 0.3) {
	 if (chassis->GetPhotoSwitch())
	 Wait(3);
	 else {
	 chassis->DriveForward(-stick->GetRawAxis(3));
	 }
	 } else {

	 chassis->DriveJoystick(stick);
	 chassis->SetCenterPower(stick->GetRawAxis(4));
	 */
	chassis->DriveCombined(stick);
	chassis->TurnInPlace(stick);
	//}
}

bool JoystickDrive::IsFinished() {
	return false;
}

void JoystickDrive::End() {

}

void JoystickDrive::Interrupted() {
	End();
}
