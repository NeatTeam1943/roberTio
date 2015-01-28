#include "../Commands/Camera/ControlCamera.h"
#include "Camera.h"
#include "../RobotMap.h"

Camera::Camera() :
		Subsystem("Camera") {
	this->side = new Servo(CAMERA_SIDE_SERVO);
	this->up = new Servo(CAMERA_UP_SERVO);
	this->xAngle = 0;
	this->zAngle = 0;
}

void Camera::InitDefaultCommand() {
	//SetDefaultCommand(new ControlCamera(CommandBase::oi->getJoystick()));
}

void Camera::LookUpDown(float value) {
	this->up->SetAngle(value);
}

void Camera::LookToSide(float value) {
	this->side->SetAngle(value);
}

void Camera::Centerize() {
	this->up->SetAngle(0);
	this->side->SetAngle(0);
}

void Camera::SavePosition() {
	this->xAngle = this->side->GetAngle();
	this->zAngle = this->up->GetAngle();
}

void Camera::ReturnToPosition() {
	this->side->SetAngle(this->xAngle);
	this->up->SetAngle(this->zAngle);
}
