//************************
// Golden Gears Robotics
// 10/30/14
// Robot MAIN
//************************

//11-6-14 - Tyler Robbins - Added header. Added some new empty methods. Added more comments. Removed old commented out code.

#include "WPILib.h"

Robot::Robot(void)
	: stick(1)

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