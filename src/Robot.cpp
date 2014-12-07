//************************
// Golden Gears Robotics
// 10/30/14
// Robot MAIN
//************************

//11-6-14 - Tyler Robbins - Added header. Added some new empty methods. Added more comments. Removed old commented out code.
//11-14-14 - Tyler Robbins - Added some more include statements. Defined a new function. Removed unused attribute.
//11-23-14 - Tyler Robbins - Added some stuff to the destructor. Added some stuff to the member initialization list in the constructor.
//12-6-14 - Tyler Robbins - Added more includes. Removed void parameter from methods. Added some new methods. Added content to TeleopPeriodic method.

#include "Robot.h"

#include "Commands/Scheduler.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

#include "OI.h"
#include "Config.h"
#include "Logging.h"
#include "HardwareMap.h"

#include "Subsystems/Drive.h"

const char* str_direction(Direction dir){
	return ((dir==Direction::UP) ? "UP":"DOWN");
}

Robot::Robot()
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

void Robot::RobotInit(){
	// Create all necessary objects here
	m_hw_map = 	new HardwareMap();
	m_oi = 		new OI();

	// m_drive = 	new Drive(&m_hw_map->left_1,
	// 	&m_hw_map->left_2,
	// 	&m_hw_map->left_3,
	// 	&m_hw_map->right_1,
	// 	&m_hw_map->right_2,
	// 	&m_hw_map->right_3);

	m_drive = new Drive();

	// Call initialization methods after everything has been constructed.
	m_hw_map->init();
	m_oi->init();

	// These send information to the dashboard so we can see what the robot is doing.
	SmartDashboard::PutData("Current Scheduler Command: ", Scheduler::GetInstance());

	SmartDashboard::PutData("Drive: ", m_drive);

}

void Robot::AutonomousPeriodic(){
	/*All Autonomous code should go here.*/
}

void Robot::TeleopInit(){
	/*
	Declares how to enable teleop mode. There really isn't anything here yet as this space will mostly be used to turn cancel autonomous mode
	and start the compressor.
	*/
	log_debug("TeleopInit()");
}

void Robot::TeleopPeriodic(){
	/*Periodically called teleop code goes in here.*/
	log_debug("TeleopPeriodic");
	Scheduler::GetInstance()->Run();
	LiveWindow::GetInstance()->SetEnabled(false);
}

void Robot::DisabledInit(){
	/*There currently isn't really anything to disable (this space is mostly reserved for autonomous code and the compressor.*/
}

void Robot::DisabledPeriodic(){
	/*Left blank because nothing happens while it is disabled*/
}

START_ROBOT_CLASS(Robot);