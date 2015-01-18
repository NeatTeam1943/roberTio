#include "Grabber.h"
#include "../RobotMap.h"

Grabber::Grabber() :
		Subsystem("Grabber") {
	this->pistons = new DoubleSolenoid(GRABBER_PISTONS_FIRST,
			GRABBER_PISTONS_SECOND);
	this->comp = new Compressor(GRABBER_COMPRESSOR);
}

void Grabber::InitDefaultCommand() {
	SetDefaultCommand(0);
}

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

void Grabber::SetCompressor(bool on) {
	if (on)
		this->comp->Start();
	else
		this->comp->Stop();
}

void Grabber::AutoCompressor() {
	if (this->comp->GetCompressorCurrent() < 120)
		this->comp->Start();
	else
		this->comp->Stop();
}
