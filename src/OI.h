#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include "Xbox/Xbox360.h"


class OI
{
private:
	Joystick *stick;
	JoystickButton* buttons[10];
	//Compressor* comp;

public:
	OI();
	Joystick* getJoystick();
	JoystickButton** GetButtons();
	//Compressor* GetComp();
	//void SwitchComp(bool isOn);
	//bool IsCompOn();
};

#endif
