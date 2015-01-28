#include "ControlCamera.h"

ControlCamera::ControlCamera(Joystick* stick) {
	Requires(camera);
	this->stick = stick;
}

// Called just before this Command runs the first time
void ControlCamera::Initialize() {
	camera->LookToSide(0);
	camera->LookUpDown(0);
}

// Called repeatedly when this Command is scheduled to run
void ControlCamera::Execute() {
	camera->LookToSide((this->stick->GetRawAxis(4) + 1) * 90);
	SmartDashboard::PutNumber("X: ", this->stick->GetRawAxis(4));
	camera->LookUpDown(this->stick->GetRawAxis(5) * 90);
	SmartDashboard::PutNumber("Y: ", this->stick->GetRawAxis(5));
}

// Make this return true when this Command no longer needs to run execute()
bool ControlCamera::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlCamera::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlCamera::Interrupted() {
	End();
}
