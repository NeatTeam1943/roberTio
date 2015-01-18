#include "ReturnToCameraPosition.h"

ReturnToCameraPosition::ReturnToCameraPosition() {
	Requires(camera);
}

// Called just before this Command runs the first time
void ReturnToCameraPosition::Initialize() {
	SetTimeout(0.1);
	camera->ReturnToPosition();
}

// Called repeatedly when this Command is scheduled to run
void ReturnToCameraPosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ReturnToCameraPosition::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ReturnToCameraPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReturnToCameraPosition::Interrupted() {
	End();
}
