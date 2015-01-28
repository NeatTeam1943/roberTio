#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Commands/Elevator/Lift.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Grabber/SwitchArms.h"
#include "Commands/Grabber/OpenArms.h"
#include "Commands/Grabber/CloseArms.h"
#include "Commands/Chassis/DriveRetarded.h"
#include "Commands/SwitchCompState.h"

OI::OI() {
	this->stick = new Joystick(JOYSTICK_CHANNEL);
	for (int i = 0; i < 10; i++) {
		this->buttons[i] = new JoystickButton(this->stick, i + 1);
	}
	//this->comp = new Compressor(COMPRESSOR_CHANNEL);

	//this->buttons[0]->WhenPressed(new Switch()); // 'A' Button
	//this->buttons[1]->WhenPressed(new SwitchCompState()); // 'B' Button
	this->buttons[0]->WhenPressed(new OpenArms());
	this->buttons[1]->WhenPressed(new CloseArms());

	this->buttons[4]->WhileHeld(new Lower()); // 'LB' Button
	this->buttons[5]->WhileHeld(new Lift()); // 'RB' Button

	//this->buttons[1]->WhileHeld(new DriveRetarded(this->stick));
	//this->buttons[1]->WhenReleased(new Lift());

	//this->comp->Start();
}

Joystick* OI::getJoystick() {
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
