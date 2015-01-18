#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "../CommandBase.h"
#include "WPILib.h"

class Grabber: public Subsystem {
private:
	DoubleSolenoid *pistons;

public:
	Grabber();
	void InitDefaultCommand();
	void SetPistonsState(DoubleSolenoid::Value value);
	void SwitchPistonsState();
	DoubleSolenoid::Value GetPistonsState();
};

#endif
