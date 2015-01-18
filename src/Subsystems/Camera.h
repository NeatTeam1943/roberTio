#ifndef Camera_H
#define Camera_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Camera: public Subsystem
{
private:
	Servo *side;
	Servo *up;
	int xAngle;
	int zAngle;


public:
	Camera();
	void InitDefaultCommand();
	void LookUpDown(float value);
	void LookToSide(float value);
	void Centerize();
	void SavePosition();
	void ReturnToPosition();
};

#endif
