#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"

OI::OI() {
	this->stick = new Joystick(JOYSTICK_CHANNEL);
	for (int i = 0; i < 10; i++) {
		this->buttons[i] = new JoystickButton(this->stick, i + 1);
	}
	this->comp = new Compressor(COMPRESSOR_CHANNEL);


	this->comp->Start();
}

Joystick* OI::getJoystick() {
	return this->stick;
}

Compressor* OI::GetComp() {
	return this->comp;
}
