//*******************
// Golden Gears Robotics
// 11/23/14
// Drive H
//*******************

// 11-23-14 - Tyler Robbins - Created a file that declaration the Drive class and its methods.
// 12-6-14 - Tyler Robbins - Added new forward declaration. Removed parameters from constructor. Made *m_def_command a constant.
// 12-11-14 - Tyler Robbins - Fixed constructor declaration. Fixed BackgroundDrive declaration.
// 12-18-14 - Tyler Robbins - Constructor now takes second left and right Talons. Changed robot_drive to driveFront/Middle/Back.

#ifndef _SUBSYSTEMS_DRIVE_H
#define _SUBSYSTEMS_DRIVE_H 

class Joystick;
class Talon;
class BackgroundDrive;

#include "Commands/Subsystem.h"
#include "RobotDrive.h"

#include "../Commands/BackgroundDrive.h"

class Drive : public Subsystem
{
public:
	// Drive(Talon *left_1, Talon *left_3, 
	// Talon *right_1, Talon *right_3,
	// Joystick *joy);
	Drive(Talon *left_1, Talon *left_2, Talon *left_3, 
	Talon *right_1, Talon *right_2, Talon *right_3,
	Joystick *joy);
	~Drive() override;

	void InitDefaultCommand() override;

	void drive(float x, float y, float turn = 0.0);

private:
	// RobotDrive robot_drive;
	RobotDrive driveFront;
	RobotDrive driveMiddle;
	RobotDrive driveBack;

	BackgroundDrive *m_def_command;
};

#endif