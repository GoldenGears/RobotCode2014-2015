//************************
// Golden Gears Robotics
// 10/30/14
// Robot MAIN
//************************

//11-6-14 - Tyler Robbins - Added header. Added some new empty methods. Added more comments. Removed old commented out code.
//11-14-14 - Tyler Robbins - Added some more include statements. Defined a new function. Removed unused attribute.
//11-23-14 - Tyler Robbins - Added some stuff to the destructor. Added some stuff to the member initialization list in the constructor.

#include "WPILib.h"

#include "HardwareMap.h"
#include "OI.h"

const char* str_direction(Direction dir){
	return ((dir==Direction::UP) ? "UP":"DOWN");
}

Robot::Robot(void)
	: m_hw_map(nullptr),
	m_oi(nullptr),
	m_drive(nullptr){

}

Robot::~Robot(){ 
	// Needed to clear memory in case the Robot class gets deleted
	// Delete in reverse construction order
	delete m_drive;
	delete m_oi;
	delete m_hw_map;
}

Robot::Autonomous(void){
	/*All Autonomous code should go here.*/
}

// Robot::OperatorControl(void){ }

Robot::TeleopPeriodic(void){
	/*Periodically called teleop code goes in here.*/
}

START_ROBOT_CLASS(Robot);