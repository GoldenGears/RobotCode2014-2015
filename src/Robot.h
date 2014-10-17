#include "WPILib.h"

class Robot : public IterativeRobot {
public:
	Robot(void);
	~Robot();

	void Autonomous(void);

	void OperatorControl(void);
}