//*******************
// Golden Gears Robotics
// 11/23/14
// Drive H
//*******************

// 11-23-14 - Tyler Robbins - Created a file that defines the Drive class and its methods.

#ifndef _SUBSYSTEMS_DRIVE_H
#define _SUBSYSTEMS_DRIVE_H 

class Joystick;
class Talon;

#include "Commands/Subsystem.h"
#include "RobotDrive.h"

#include "../Commands/BackgroundDrive.h"

class Drive : public Subsystem
{
public:
	Drive(Talon *front_l, Talon *front_r,
		Talon back_l, Talon back_r, Joystick *joy);
	~Drive() override;

	void InitDefaultCommand() override;

	void drive(float x, float y, float turn = 0.0);

private:
	RobotDrive robot_drive;

	BackgroundDrive *m_def_command;
};

#endif