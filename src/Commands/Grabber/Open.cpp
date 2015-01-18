#include "Open.h"

Open::Open() {
	Requires(grabber);
}

// Called just before this Command runs the first time
void Open::Initialize() {
	SetTimeout(1);
	grabber->SetPistonsState(DoubleSolenoid::Value::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void Open::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Open::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Open::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Open::Interrupted() {
	End();
}
