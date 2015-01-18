#include "SaveCameraPosition.h"

SaveCameraPosition::SaveCameraPosition() {
	Requires(camera);
}

// Called just before this Command runs the first time
void SaveCameraPosition::Initialize() {
	SetTimeout(0.1);
	camera->SavePosition();
}

// Called repeatedly when this Command is scheduled to run
void SaveCameraPosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SaveCameraPosition::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void SaveCameraPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SaveCameraPosition::Interrupted() {
	End();
}
