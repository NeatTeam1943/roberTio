#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	CANTalon *left;
	CANTalon *right;
	//RobotDrive * drive;
	CANTalon *centerMotor;
	DigitalInput *ps; //  photoSwitch

public:
	Chassis();
	void InitDefaultCommand();
	void Drive(float x, float y);
	void DriveJoystick(Joystick *stick);
	void DriveRightStick(Joystick *stick);
	void CarDriveJoystick(Joystick *stick);
	void DriveCombined(Joystick *stick);
	void SetCenterPower(float axis);
	void TurnInPlace(Joystick *stick);
	void DriveForward(float axis);
	bool GetPhotoSwitch();
};

#endif
