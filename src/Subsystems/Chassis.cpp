#include <Commands/Chassis/CarJoystickDrive.h>
#include <Commands/Chassis/JoystickDrive.h>
#include "Chassis.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

Chassis::Chassis() :
<<<<<<< HEAD
		Subsystem("Chassis") {
	this->left = new CANTalon(CHASSIS_LEFT_MOTOR_CAN);
	this->right = new CANTalon(CHASSIS_RIGHT_MOTOR_CAN);
	this->drive = new RobotDrive(this->left, this->right);
	this->centerMotor = new CANTalon(CHASSIS_CENTER_MOTOR_CAN);
	this->ps = new DigitalInput(CHASSIS_SWITCH);
=======
	Subsystem("Chassis") {
	this->drive = new RobotDrive(RIGHT_MOTOR, LEFT_MOTOR);
>>>>>>> b083bdbb245c87a3bb3be1922a8b880e525d573d
}

void Chassis::InitDefaultCommand() {
//	this->SetDefaultCommand(
//			new CarJoystickDrive(CommandBase::oi->getJoystick()));
	this->SetDefaultCommand(new JoystickDrive(CommandBase::oi->getJoystick()));
}

void Chassis::Drive(float x, float y) {
<<<<<<< HEAD
	this->drive->ArcadeDrive(y, x, false);
=======
	drive->ArcadeDrive(y, x, false);

>>>>>>> b083bdbb245c87a3bb3be1922a8b880e525d573d
}

void Chassis::DriveJoystick(Joystick *stick) {
	float x = 0, y = 0;
	if (-stick->GetY() > 0.1 || -stick->GetY() < -0.1)
		y = -stick->GetY();
	if (stick->GetX() > 0.1 || stick->GetX() < -0.1)
		x = stick->GetX();
	this->drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveRightStick(Joystick *stick) {
	float x = 0, y = 0;
	if (-stick->GetRawAxis(5) > 0.1 || -stick->GetRawAxis(5) < -0.1)
		y = -stick->GetRawAxis(5);
	if (stick->GetRawAxis(4) > 0.1 || stick->GetRawAxis(4) < -0.1)
		x = stick->GetRawAxis(4);
	this->drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveForward(float power) {
	this->left->Set(power);
	this->right->Set(power);
}

void Chassis::CarDriveJoystick(Joystick *stick) {
	if (stick->GetThrottle() > 0)
		this->drive->ArcadeDrive(stick->GetThrottle(), stick->GetX(), false);
	else
		this->drive->ArcadeDrive(stick->GetZ(), stick->GetX(), false);
}

void Chassis::SetCenterPower(float power) {
	this->centerMotor->Set(power);
}

bool Chassis::GetPhotoSwitch() {
	return this->ps->Get();
}
