#include "DownSwitchSchnitzel.h"

DownSwitchSchnitzel::DownSwitchSchnitzel()
{
	SetInterruptible(false);
}

// Called just before this Command runs the first time
void DownSwitchSchnitzel::Initialize()
{
	elevator->Move(0);
	SetTimeout(0.1);
}

// Called repeatedly when this Command is scheduled to run
void DownSwitchSchnitzel::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DownSwitchSchnitzel::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DownSwitchSchnitzel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DownSwitchSchnitzel::Interrupted()
{	}
