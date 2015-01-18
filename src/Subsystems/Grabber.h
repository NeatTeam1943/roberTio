#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem {
private:
	DoubleSolenoid *pistons;
	Compressor *comp;

public:
	Grabber();
	void InitDefaultCommand();
	void SetPistonsState(DoubleSolenoid::Value value);
	void SwitchPistonsState();
	DoubleSolenoid::Value GetPistonsState();
	void SetCompressor(bool on);
	int GetCompPressure();
	void AutoCompressor();
};

#endif
