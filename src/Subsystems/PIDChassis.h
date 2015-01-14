#ifndef PIDChassis_H
#define PIDChassis_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class PIDChassis: public PIDSubsystem
{
public:
	PIDChassis();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
