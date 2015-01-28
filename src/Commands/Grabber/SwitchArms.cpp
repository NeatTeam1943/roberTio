#include "SwitchArms.h"

SwitchArms::SwitchArms() {
	Requires(grabber);
}

// Called just before this Command runs the first time
void SwitchArms::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SwitchArms::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool SwitchArms::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SwitchArms::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchArms::Interrupted() {

}
