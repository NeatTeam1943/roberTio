#include "SwitchCompState.h"

SwitchCompState::SwitchCompState()
{
}

// Called just before this Command runs the first time
void SwitchCompState::Initialize()
{
	SetTimeout(0.3);
	//oi->SwitchComp(!oi->IsCompOn());
}

// Called repeatedly when this Command is scheduled to run
void SwitchCompState::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SwitchCompState::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SwitchCompState::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchCompState::Interrupted()
{

}
