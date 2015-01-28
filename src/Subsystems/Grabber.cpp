#include "Grabber.h"
#include "../RobotMap.h"

Grabber::Grabber() :
		Subsystem("Grabber") {
	//this->pistons = new DoubleSolenoid(GRABBER_PISTONS_FIRST,
	//	GRABBER_PISTONS_SECOND);
	//this->motor = new CANTalon(GRABBER_MOTOR_CAN);
	this->motor = new Talon(GRABBER_MOTOR_CHANNEL);
	this->openS = new DigitalInput(GRABBER_OPEN_SWITCH);
	this->closeS = new DigitalInput(GRABBER_CLOSE_SWITCH);
}

void Grabber::InitDefaultCommand() {
	SetDefaultCommand(0);
}

void Grabber::SetMotorPower(float power) {
	this->motor->Set(power);
}

bool Grabber::IsOpen() {
	return this->openS->Get();
}

bool Grabber::IsClose() {
	return this->closeS->Get();
}

/*
 void Grabber::SetPistonsState(DoubleSolenoid::Value value) {
 this->pistons->Set(value);
 }

 DoubleSolenoid::Value Grabber::GetPistonsState() {
 return this->pistons->Get();
 }

 void Grabber::SwitchPistonsState() {
 if (GetPistonsState() == DoubleSolenoid::Value::kForward)
 this->pistons->Set(DoubleSolenoid::Value::kReverse);
 else if (GetPistonsState() == DoubleSolenoid::Value::kReverse)
 this->pistons->Set(DoubleSolenoid::Value::kForward);
 }
 */
