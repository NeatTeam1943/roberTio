#include "OI.h"

OI::OI()
{
	this->stick= new Xbox360(CONTROLLER_CHANNEL);
}

Xbox360* OI::getJoystick(){
	return this->stick;
}
