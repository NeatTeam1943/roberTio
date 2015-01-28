#include "ElevatorLiftByPOV.h"
ElevatorLiftByPOV::ElevatorLiftByPOV(Joystick* stick) {
	Requires(elevator);
	this->stick = stick;
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ElevatorLiftByPOV::Initialize() {
	//elevator->motor->
}

// Called repeatedly when this Command is scheduled to run
void ElevatorLiftByPOV::Execute() {
	if (!(elevator->GetUpSwitch() || elevator->GetDownSwitch())) {
		if (stick->GetPOV() < 90 || stick->GetPOV() > 270)
			elevator->Move(0.5);
		else if (stick->GetPOV() > 90 && stick->GetPOV() < 270)
			elevator->Move(-0.5);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorLiftByPOV::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorLiftByPOV::End() {
	elevator->Move(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorLiftByPOV::Interrupted() {
	End();
}
