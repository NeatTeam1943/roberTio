#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem {
private:
	//DoubleSolenoid *pistons;
	CANTalon *motor;
	//Talon *motor;
	DigitalInput *openS;
	DigitalInput *closeS;

public:
	Grabber();
	void InitDefaultCommand();
	void SetMotorPower(float power);
	bool IsOpen();
	bool IsClose();

	/*
	 void SetPistonsState(DoubleSolenoid::Value value);
	 void SwitchPistonsState();
	 DoubleSolenoid::Value GetPistonsState();
	 */
};

#endif
