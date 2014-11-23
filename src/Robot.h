//*******************
// Golden Gears Robotics
// 11/6/14
// Robot H
//*******************

// 11-6-14 - Tyler Robbins - Added a header. Added more imports. Added define statements. Defined more methods and variables.
// 11-13-14 - Tyler Robbins - Added an enumeration. Defined a new function.
// 11-22-14 - Tyler Robbins - Added some more include statements. Removed an unused variable and some commented out code. Added some more class members.

#include "WPILib.h"
#include "RobotBase.h"
#include "IterativeRobot.h"

#include "HardwareMap.h"
#include "OI.h"

#include "Subsystems/MotorSubsystem.h"

#ifndef _ROBOT_H_
#define _ROBOT_H_

enum class Direction {UP,DOWN};

const char* str_direction(Direction dir);

class Robot : public IterativeRobot {
	
public:
	~Robot();

	static Robot& instance(){ return (Robot&) RobotBase::getInstance(); };

	void RobotInit(void) override;

	void AutonomousPeriodic(void) override;

	void TeleopInit(void) override;
	void TeleopPeriodic(void) override;

private:
	HardwareMap* m_hw_map;

	OI* m_oi;

	Drive* m_drive;

	friend RobotBase* FRC_userClassFactory();

	Robot();
};

#endif