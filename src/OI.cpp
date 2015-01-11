#include "OI.h"

OI::OI()
{
	this->stick= new Joystick(JOYSTICK_CHANNEL);
}

Joystick* OI::getJoystick(){
	return this->stick;
}
