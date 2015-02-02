/*
 * Xbox.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Neat Team
 */

#include "Joysticks/Xbox.h"

/* The buttons on the controller follow this mapping
 * 1: A
 * 2: B
 * 3: X
 * 4: Y
 * 5: Left Bumper
 * 6: Right Bumper
 * 7: Back
 * 8: Start
 * 9: Left Joystick
 * 10: Right Joystick
 */
/* The axis on the controller follow this mapping
 * 1: Left Stick X Axis
 *      -Left:Negative ; Right: Positive
 * 2: Left Stick Y Axis
 *      -Up: Negative ; Down: Positive
 * 3: Triggers
 *      -Left: Positive ; Right: Negative
 * 4: Right Stick X Axis
 *      -Left: Negative ; Right: Positive
 * 5: Right Stick Y Axis
 *      -Up: Negative ; Down: Positive
 * 6: Directional Pad (Not recommended, buggy)
 */

Xbox::Xbox(int port) :
		Joystick(port) {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < 10; i++) {
		this->buttons[i] = new JoystickButton(this, i + 1);
	}
}

// 	Axes
float Xbox::GetLeftX() {
	if (GetRawAxis(1) < -0.1 || GetRawAxis(1) > 0.1)
		return GetRawAxis(1);
	else
		return 0;
}
float Xbox::GetLeftY() {
	if (GetRawAxis(2) < -0.1 || GetRawAxis(2) > 0.1)
		return -GetRawAxis(2);
	else
		return 0;
}
float Xbox::GetRightX() {
	if (GetRawAxis(4) < -0.1 || GetRawAxis(4) > 0.1)
		return GetRawAxis(4);
	else
		return 0;
}
float Xbox::GetRightY() {
	if (GetRawAxis(5) < -0.1 || GetRawAxis(5) > 0.1)
		return -GetRawAxis(5);
	else
		return 0;
}
float Xbox::GetTriggers() {
	if (GetRawAxis(3) < -0.1 || GetRawAxis(3) > 0.1)
		return -GetRawAxis(3);
	else
		return 0;
}

//	Buttons
JoystickButton* Xbox::GetAButton() {
	return this->buttons[0];
}
JoystickButton* Xbox::GetBButton() {
	return this->buttons[1];
}
JoystickButton* Xbox::GetXButton() {
	return this->buttons[2];
}
JoystickButton* Xbox::GetYButton() {
	return this->buttons[3];
}
JoystickButton* Xbox::GetRightBumper() {
	return this->buttons[4];
}
JoystickButton* Xbox::GetLeftBumper() {
	return this->buttons[5];
}
JoystickButton* Xbox::GetBack() {
	return this->buttons[6];
}
JoystickButton* Xbox::GetStart() {
	return this->buttons[7];
}
JoystickButton* Xbox::GetLeftStickButton() {
	return this->buttons[8];
}
JoystickButton* Xbox::GetRightStickButton() {
	return this->buttons[9];
}

//	Button Values
bool Xbox::GetAButtonValue() {
	return this->buttons[0]->Get();
}
bool Xbox::GetBButtonValue() {
	return this->buttons[1]->Get();
}
bool Xbox::GetXButtonValue() {
	return this->buttons[2]->Get();
}
bool Xbox::GetYButtonValue() {
	return this->buttons[3]->Get();
}
bool Xbox::GetRightBumperValue() {
	return this->buttons[4]->Get();
}
bool Xbox::GetLeftBumperValue() {
	return this->buttons[5]->Get();
}
bool Xbox::GetBackValue() {
	return this->buttons[6]->Get();
}
bool Xbox::GetStartValue() {
	return this->buttons[7]->Get();
}
bool Xbox::GetLeftStickButtonValue() {
	return this->buttons[8]->Get();
}
bool Xbox::GetRightStickButtonValue() {
	return this->buttons[9]->Get();
}

//	Convenience
bool Xbox::GetRawButton(uint32_t button) {
	return Joystick::GetRawButton(button);
}

float Xbox::GetRawAxis(uint32_t axis) {
	return Joystick::GetRawAxis(axis);
}

int Xbox::GetPOV() {
	return Joystick::GetPOV();
}
