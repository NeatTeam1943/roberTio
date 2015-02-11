#include "DriveRS.h"

DriveRS::DriveRS(Joystick *stick) {
	//Requires(chassis);
	this->stick = stick;
}

// Called just before this Command runs the first time
void DriveRS::Initialize() {
	chassis->SetCenterPower(0);
}

// Called repeatedly when this Command is scheduled to run
void DriveRS::Execute() {
	chassis->SetCenterPower(this->stick->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveRS::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveRS::End() {
	chassis->SetCenterPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveRS::Interrupted() {
	End();
}
