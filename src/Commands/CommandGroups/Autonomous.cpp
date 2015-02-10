#include "Autonomous.h"
#include "../Elevator/Lift.h"
#include "../Elevator/Lower.h"
#include "../Grabber/CloseArms.h"
#include "../Chassis/DriveForward.h"
#include "../Chassis/JoystickDrive.h"

Autonomous::Autonomous() {
	AddSequential(new Lower());
	AddSequential(new CloseArms());
	AddSequential(new Lift(), 5);
	//AddSequential(new DriveForward(-0.5), 3);
}
