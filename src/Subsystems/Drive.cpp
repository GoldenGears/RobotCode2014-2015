//*******************
// Golden Gears Robotics
// 11/23/14
// Drive MAIN
//*******************

// 11-23-14 - Tyler Robbins - Created a file that declares the Drive class and its methods.
// 12-6-14 - Tyler Robbins - Removed includes for Joystick and Talon. Changed robot_drive initialization. Specified InitDefaultCommand and drive as void.

#include "Drive.h"

#include "RobotDrive.h"
// #include "Joystick.h"
// #include "Talon.h"

#include "../Commands/BackgroundDrive.h"
#include "../Robot.h"

Drive::Drive()
	: Subsystem("Drive"),
	robot_drive(&Robot::hw_map()->left_1,
				&Robot::hw_map()->left_3,
				&Robot::hw_map()->right_1,
				&Robot::hw_map()->right_3)
	,m_def_command(this,&Robot::oi()->joy)
	{

	robot_drive.SetExpiration(0.5);

	// In case any of the motors are inverted, we can correct them by un-commenting the corresponding motor

	// robot_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor,true);		// Front Left
	// robot_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor,true);		// Front Right
	// robot_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,true);		// Rear Left
	// robot_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,true);		// Rear Right
	}

Drive::~Drive() {}

void Drive::InitDefaultCommand(){
	// Background drive should be run when nothing else is using this subsystem.
	SetDefaultCommand(&m_def_command);
	// SetDefaultCommand(new BackgroundDrive(Robot::drive()));
}

void Drive::drive(float x, float y, float turn){
	// y is used so that when we push the joystick forwards, the robot moves forwards.
	// We should probably add code to use different driving methods depending on driver preference, but this should be good enough for now.
	robot_drive.ArcadeDrive(y,turn); 
}