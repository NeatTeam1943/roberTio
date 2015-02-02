/*
 * Xbox.h
 *
 *  Created on: Feb 2, 2015
 *  	Author: Roy Bar-On
 *		Team  : NeatTeam #1943
 */

#ifndef SRC_JOYSTICKS_XBOX_H_
#define SRC_JOYSTICKS_XBOX_H_

#include <WPILib.h>

class Xbox: public Joystick {
private:
	JoystickButton *buttons[10];

public:
	Xbox(int port);

	// 	Axes
	float GetLeftY();
	float GetLeftX();
	float GetRightY();
	float GetRightX();
	float GetTriggers();

	//	Buttons
	JoystickButton* GetAButton();
	JoystickButton* GetBButton();
	JoystickButton* GetXButton();
	JoystickButton* GetYButton();
	JoystickButton* GetRightBumper();
	JoystickButton* GetLeftBumper();
	JoystickButton* GetBack();
	JoystickButton* GetStart();
	JoystickButton* GetLeftStickButton();
	JoystickButton* GetRightStickButton();

	//	Button Values
	bool GetAButtonValue();
	bool GetBButtonValue();
	bool GetXButtonValue();
	bool GetYButtonValue();
	bool GetRightBumperValue();
	bool GetLeftBumperValue();
	bool GetBackValue();
	bool GetStartValue();
	bool GetLeftStickButtonValue();
	bool GetRightStickButtonValue();

	//	Convenience
	bool GetRawButton(uint32_t button);
	float GetRawAxis(uint32_t axis);
	int GetPOV();
};

#endif /* SRC_JOYSTICKS_XBOX_H_ */
