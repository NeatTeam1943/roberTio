#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"

OI::OI() {
	this->stick = new Joystick(JOYSTICK_CHANNEL);
	for (int i = 0; i < 10; i++) {
		this->buttons[i] = new JoystickButton(this->stick, i + 1);
	}
}

Joystick* OI::getJoystick() {
	return this->stick;
}
