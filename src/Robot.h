//*******************
// Golden Gears Robotics
// 11/6/14
// Robot H
//*******************

// 11-6-14 - Tyler Robbins - Added a header. Added more imports. Added define statements. Defined more methods and variables.
// 11-13-14 - Tyler Robbins - Added an enumeration. Defined a new function.
// 11-23-14 - Tyler Robbins - Added some more include statements. Removed an unused variable and some commented out code. Added some more class members.
// 12-6-14 - Tyler Robbins - Added a forward declaration for the Drive class. Added some new methods and removed the void parameter from all other methods. Changed constructor to be private.

#include "WPILib.h"
#include "RobotBase.h"
#include "IterativeRobot.h"

#include "HardwareMap.h"
#include "OI.h"

#include "Subsystems/MotorSubsystem.h"

#ifndef _ROBOT_H_
#define _ROBOT_H_

class Drive;

enum class Direction {UP,DOWN};

const char* str_direction(Direction dir);

class Robot : public IterativeRobot {
	
public:
	~Robot();

	static Robot& instance(){ return (Robot&) RobotBase::getInstance(); };

	void RobotInit() override;

	void AutonomousPeriodic() override;

	void TeleopInit() override;
	void TeleopPeriodic() override;

	void DisabledInit() override;
	void DisabledPeriodic() override;

	static HardwareMap* hw_map() { return instance().m_hw_map; };
	static Drive* drive() { return instance().m_drive; };
	static OI* oi() { return instance().m_oi; };

private:
	Robot();

	HardwareMap* m_hw_map;

	OI* m_oi;

	Drive* m_drive;

	friend RobotBase* FRC_userClassFactory();
};

#endif