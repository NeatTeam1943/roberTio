#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"


class OI
{
private:
	Joystick *stick;
	JoystickButton* buttons[10];
	//Compressor* comp;

public:
	OI();
	Joystick* getJoystick();
	//Compressor* GetComp();
	JoystickButton** GetButtons();
	//void SwitchComp(bool isOn);
	//bool IsCompOn();
};

#endif
