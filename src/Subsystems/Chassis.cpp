#include <Commands/Chassis/JoystickDrive.h>
#include "Chassis.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

Chassis::Chassis() :
		Subsystem("Chassis") {
	this->left = new CANTalon(CHASSIS_LEFT_MOTOR_CAN);
	this->right = new CANTalon(CHASSIS_RIGHT_MOTOR_CAN);
	this->drive = new RobotDrive(this->left, this->right);
	this->centerMotor1 = new CANTalon(CHASSIS_CENTER_MOTOR1_CAN);
	this->centerMotor2 = new CANTalon(CHASSIS_CENTER_MOTOR2_CAN);
	this->ps = new DigitalInput(CHASSIS_SWITCH);
}

void Chassis::InitDefaultCommand() {
	this->SetDefaultCommand(new JoystickDrive(CommandBase::oi->getJoystick()));
}

void Chassis::Drive(float move, float rotation) {
	this->drive->ArcadeDrive(move, rotation, false);
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

void Chassis::DriveCombined(Joystick *stick) {
	if (stick->GetY() > 0.15 || stick->GetY() < -0.15) {
		this->left->Set(-stick->GetY());
		this->right->Set(stick->GetY());
	} else {
		this->left->Set(0);
		this->right->Set(0);
	}
	if (stick->GetX() > 0.15 || stick->GetX() < -0.15) {
		this->centerMotor1->Set(-stick->GetX());
		this->centerMotor2->Set(-stick->GetX());
	} else {
		this->centerMotor1->Set(0);
		this->centerMotor2->Set(0);
	}

}

void Chassis::TurnInPlace(Joystick *stick) {

	float axis = stick->GetRawAxis(4);
	if (axis > 0.15 || axis < -0.15) {
		this->left->Set(axis);
		this->right->Set(axis);
	}
	/*
	 if (stick->GetPOV() == 90) {
	 this->left->Set(0.75);
	 this->right->Set(0.75); // goes back
	 }
	 else if (stick->GetPOV() == 270) {
	 this->left->Set(-0.75);
	 this->right->Set(-0.75);
	 }
	 else {
	 this->left->Set(0);
	 this->right->Set(0);
	 }
	 */
}

void Chassis::SetCenterPower(float power) {
	if (power > 0.2 || power < -0.2) {
		this->centerMotor1->Set(-power);
		this->centerMotor2->Set(-power);
	} else {
		this->centerMotor1->Set(0);
		this->centerMotor2->Set(0);
	}
}

bool Chassis::GetPhotoSwitch() {
	return this->ps->Get();
}
