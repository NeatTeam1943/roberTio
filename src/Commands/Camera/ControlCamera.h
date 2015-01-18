#ifndef ControlCamera_H
#define ControlCamera_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ControlCamera: public CommandBase
{
private:
	Joystick* stick;
public:
	ControlCamera(Joystick* stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
