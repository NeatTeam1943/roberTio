#include "SwitchArmsState.h"

SwitchArmsState::SwitchArmsState() {
	Requires(grabber);
	this->isToOpen = false;
}

// Called just before this Command runs the first time
void SwitchArmsState::Initialize() {
	this->isToOpen = !grabber->IsOpen();
}

// Called repeatedly when this Command is scheduled to run
void SwitchArmsState::Execute() {
	if (this->isToOpen) {
		grabber->SetMotorPower(0.5);
	}
	else
		grabber->SetMotorPower(-0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool SwitchArmsState::IsFinished() {
	if (this->isToOpen)
		return grabber->IsOpen();
	else
		return grabber->IsClose();
}

// Called once after isFinished returns true
void SwitchArmsState::End() {
	grabber->SetMotorPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchArmsState::Interrupted() {
	End();
}
