#include "CloseArms.h"

CloseArms::CloseArms() {
	Requires(grabber);
}

// Called just before this Command runs the first time
void CloseArms::Initialize() {
	SetTimeout(0.5);
}

// Called repeatedly when this Command is scheduled to run
void CloseArms::Execute() {
	grabber->SetMotorPower(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool CloseArms::IsFinished() {
	return grabber->IsClose() || IsTimedOut();
}

// Called once after isFinished returns true
void CloseArms::End() {
	grabber->SetMotorPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseArms::Interrupted() {
	End();
}
