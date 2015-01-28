#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include "Xbox/Xbox360.h"


class OI
{
private:
<<<<<<< HEAD
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
=======
	Xbox360 *stick;
public:
	OI();
	Xbox360* getJoystick();
>>>>>>> b083bdbb245c87a3bb3be1922a8b880e525d573d
};

#endif
