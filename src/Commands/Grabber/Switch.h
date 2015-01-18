#ifndef Switch_H
#define Switch_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Switch: public CommandBase {
public:
	Switch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
