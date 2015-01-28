#include "DriveRetarded.h"

DriveRetarded::DriveRetarded(Joystick* stick) {
	Requires(chassis);
	this->stick = stick;
}

// Called just before this Command runs the first time
void DriveRetarded::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveRetarded::Execute() {
	if (!chassis->GetPhotoSwitch() && oi->GetButtons()[8]->Get()) {
		if (stick->GetZ() < -0.05)
			chassis->DriveForward(-stick->GetZ());
	} else {
		Wait(2);
		End();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveRetarded::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveRetarded::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveRetarded::Interrupted() {

}
