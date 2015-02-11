#include "DriveLS.h"

DriveLS::DriveLS(Joystick *stick) {
	//Requires(chassis);
	this->stick = stick;
}

// Called just before this Command runs the first time
void DriveLS::Initialize() {
	chassis->Drive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveLS::Execute() {
	if (this->stick->GetRawAxis(3) > 0.3 && !chassis->GetPhotoSwitch()) {
		chassis->Drive(stick->GetRawAxis(3), 0);
	} else {
		chassis->DriveJoystick(this->stick);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLS::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveLS::End() {
	chassis->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLS::Interrupted() {
	End();
}
