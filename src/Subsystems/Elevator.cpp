#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() :
		Subsystem("Elevator") {
	this->motor = new Talon(ELEVATOR_MOTOR);
	this->upSwitch = new DigitalInput(ELEVATOR_UP_SWITCH);
	this->downSwitch = new DigitalInput(ELEVATOR_DOWN_SWITCH);
}

void Elevator::InitDefaultCommand() {
	SetDefaultCommand(0);
}

void Elevator::Move(float power) {
	this->motor->Set(power);
}

bool Elevator::GetUpSwitch() {
	return this->upSwitch->Get();
}

bool Elevator::GetDownSwitch() {
	return this->downSwitch->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
