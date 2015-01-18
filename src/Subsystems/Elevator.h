#ifndef Elevator_H
#define Elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:
	DigitalInput *upSwitch;
	DigitalInput *downSwitch;
	Talon *motor;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Elevator();
	void InitDefaultCommand();
	void Move(float power);
	bool GetUpSwitch();
	bool GetDownSwitch();

};

#endif
