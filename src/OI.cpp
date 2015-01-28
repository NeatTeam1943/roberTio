#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Commands/Elevator/Lift.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Grabber/SwitchArmsState.h"
#include "Commands/Chassis/DriveRetarded.h"

OI::OI() {
	this->stick = new Joystick(JOYSTICK_CHANNEL);
	for (int i = 0; i < 10; i++) {
		this->buttons[i] = new JoystickButton(this->stick, i + 1);
	}

	this->buttons[0]->WhenPressed(new SwitchArmsState()); // 'A' Button

	this->buttons[4]->WhileHeld(new Lower()); // 'LB' Button
	this->buttons[5]->WhileHeld(new Lift()); // 'RB' Button

}

Joystick* OI::getJoystick(){
	return this->stick;
}


JoystickButton** OI::GetButtons() {
	return this->buttons;
}

/*Compressor* OI::GetComp() {
	return this->comp;
}

void OI::SwitchComp(bool toStart) {
	if (toStart)
		this->comp->Start();
	else
		this->comp->Stop();
}

bool OI::IsCompOn() {
	return this->comp->Enabled();
}
*/
