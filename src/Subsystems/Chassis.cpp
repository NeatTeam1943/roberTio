#include <Commands/Chassis/JoystickDrive.h>
#include "Chassis.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

Chassis::Chassis() :
		Subsystem("Chassis") {
	this->left = new CANTalon(CHASSIS_LEFT_MOTOR_CAN);
	this->right = new CANTalon(CHASSIS_RIGHT_MOTOR_CAN);
	this->drive = new RobotDrive(this->left, this->right);
	this->centerMotor = new CANTalon(CHASSIS_CENTER_MOTOR_CAN);
	this->ps = new DigitalInput(CHASSIS_SWITCH);
}

void Chassis::InitDefaultCommand() {
	this->SetDefaultCommand(
		new JoystickDrive(CommandBase::oi->getJoystick()));
}

void Chassis::Drive(float x, float y) {
	drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveJoystick(Joystick *stick) {
	float x = 0, y = 0;
	if (stick->GetY() > 0.2 || stick->GetY() < -0.2)
		y = -stick->GetY();
	if (stick->GetX() > 0.2 || stick->GetX() < -0.2)
		x = -stick->GetX();
	this->drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveRightStick(Joystick *stick) {
	float x = 0, y = 0;
	if (stick->GetRawAxis(5) > 0.2 || -stick->GetRawAxis(5) < -0.2)
		y = stick->GetRawAxis(5);
	if (stick->GetRawAxis(4) > 0.2 || -stick->GetRawAxis(4) < -0.2)
		x = stick->GetRawAxis(4);
	this->drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveForward(float power) {
	this->left->Set(power);
	this->right->Set(power);
}

void Chassis::DriveCombined(Joystick *stick) {
	float forward, sides;
	if (stick->GetY() > 0.2 || stick->GetY() < -0.2)
		forward = stick->GetY();
	else forward = 0;
	if (stick->GetX() > 0.2 || stick->GetX() < -0.2)
		sides = stick->GetX() * 0.75;
	else sides = 0;

	this->left->Set(forward);
	this->right->Set(forward);
	this->centerMotor->Set(sides);
}

void Chassis::TurnInPlace(float axis) {
	if (axis > 0.1 || axis < -0.1) {
		this->left->Set(axis);
		this->right->Set(-axis);
	}
}

void Chassis::SetCenterPower(float power) {
	if (power > 0.2 || power < -0.2)
		this->centerMotor->Set(-power);
	else
		this->centerMotor->Set(0);
}

bool Chassis::GetPhotoSwitch() {
	return this->ps->Get();
}
