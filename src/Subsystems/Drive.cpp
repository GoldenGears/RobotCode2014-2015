//*******************
// Golden Gears Robotics
// 11/23/14
// Drive MAIN
//*******************

// 11-23-14 - Tyler Robbins - Created a file that declares the Drive class and its methods.

#include "Drive.h"

#include "RobotDrive.h"
#include "Joystick.h"
#include "Talon.h"

#include "../Commands/BackgroundDrive.h"
#include "../Robot.h"

Drive::Drive(Talon *front_l, Talon *front_r,
	Talon back_l, Talon back_r, Joystick *joy)
	: Subsystem("Drive"),
	robot_drive(front_l,
		back_l,
		front_r,
		back_r),
	m_def_command(this,joy){

	robot_drive.SetExpiration(0.5);

	// In case any of the motors are inverted, we can correct them by un-commenting the corresponding motor

	// robot_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor,true);		// Front Left
	// robot_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor,true);		// Front Right
	// robot_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,true);		// Rear Left
	// robot_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,true);		// Rear Right
	}

Drive::~Drive() {}

Drive::InitDefaultCommand(){
	// Background drive should be run when nothing else is using this subsystem.
	SetDefaultCommand(&m_def_command);
}

Drive::drive(float x, float y, float turn){
	// y is used so that when we push the joystick forwards, the robot moves forwards.
	// We should probably add code to use different driving methods depending on driver preference, but this should be good enough for now.
	robot_drive.ArcadeDrive(y,turn); 
}