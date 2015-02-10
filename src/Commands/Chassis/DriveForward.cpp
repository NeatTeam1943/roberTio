#include "Commands/Chassis/DriveForward.h"

DriveForward::DriveForward(float power) {
	//Requires(chassis);
	this->power = power;
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	chassis->Drive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	chassis->Drive(this->power, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveForward::End() {
	chassis->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {
	End();
}
