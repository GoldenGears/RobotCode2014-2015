//*******************
// Golden Gears Robotics
// 11/6/14
// Robot H
//*******************

// 11-6-14 - Tyler Robbins - Added a header. Added more imports. Added define statements. Defined more methods and variables.

#include "WPILib.h"
#include "RobotBase.h"
#include "IterativeRobot.h"

#ifndef _ROBOT_H_
#define _ROBOT_H_

class Robot : public IterativeRobot {
	Joystick stick;
	
public:
	~Robot();

	static Robot& instance(){ return (Robot&) RobotBase::getInstance(); };

	void RobotInit(void) override;

	void AutonomousPeriodic(void) override;

	// void OperatorControl(void);

	void TeleopInit(void) override;
	void TeleopPeriodic(void) override;

private:
	friend RobotBase* FRC_userClassFactory();

	Robot();
};

#endif