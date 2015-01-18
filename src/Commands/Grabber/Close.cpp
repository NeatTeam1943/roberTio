#include "Close.h"

Close::Close() {
	Requires(grabber);
}

// Called just before this Command runs the first time
void Close::Initialize() {
	SetTimeout(1);
	grabber->SetPistonsState(DoubleSolenoid::Value::kForward);
}

// Called repeatedly when this Command is scheduled to run
void Close::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Close::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Close::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Close::Interrupted() {
	End();
}
