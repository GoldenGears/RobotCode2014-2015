//************************
// Golden Gears Robotics
// 10/30/14
// Robot MAIN
//************************

//11-6-14 - Tyler Robbins - Added header. Added some new empty methods. Added more comments. Removed old commented out code.
//11-14-14 - Tyler Robbins - Added some more include statements. Defined a new function. Removed unused attribute.

#include "WPILib.h"

#include "HardwareMap.h"
#include "OI.h"

const char* str_direction(Direction dir){
	return ((dir==Direction::UP) ? "UP":"DOWN");
}

Robot::Robot(void)
	:

	/*Initialize all necessary variables*/
	{ }

Robot::~Robot(){ }

Robot::Autonomous(void){
	/*All Autonomous code should go here.*/
}

// Robot::OperatorControl(void){ }

Robot::TeleopPeriodic(void){
	/*Periodically called teleop code goes in here.*/
}

START_ROBOT_CLASS(Robot);