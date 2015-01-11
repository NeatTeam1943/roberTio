#include "OI.h"

OI::OI()
{
	stick = new Joystick(1);
}

OI::getJoystick(){
	return this->stick;
}
