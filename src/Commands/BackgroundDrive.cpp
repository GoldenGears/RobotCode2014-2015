//*******************
// Golden Gears Robotics
// 11/23/14
// Background Drive MAIN
//*******************

// 11-23-14 - Tyler Robbins - Created a file that declares the BackgroundDrive class and its methods.
// 12-6-14 - Tyler Robbins - Added new include and forward class declaration. Constructor now only accepts one parameter. Specified the type of methods. joy is now gotten directly from Robot::oi().
// 12-11-14 - Tyler Robbins - Fixed method override of IsFinished(). Fixed constructor. Added more comments.

#include "BackgroundDrive.h"
#include "Joystick.h"

#include "../Subsystems/Drive.h"
#include "../Robot.h"

class Drive;

BackgroundDrive::BackgroundDrive(Drive* drive, Joystick *joy)
	: Command("BackgroundDrive")
	,m_drive(drive)
	,m_joy(joy)
	{
		Requires(drive);
}

BackgroundDrive::~BackgroundDrive(){}

void BackgroundDrive::Initialize(){}

void BackgroundDrive::Execute(){
	Joystick &joy = Robot::oi()->joy;
	float x,y,turn,throttle;

	x = joy.GetX();
	y = joy.GetY();

	turn = joy.GetThrottle(); // For some wierd reason, these are swapped according to last year's code.
	throttle = joy.GetTwist(); // We should test this just to be sure though.

	// Add 1 to shift the values and then divide by 2 to scale down
	throttle = (-throttle + 1.0)/2.0; // This is done to make the throttle values go from 0 to 1 instead of -1 to 1. This makes it easier to understand what the values do.

	// In case any values need to be inverted, simply un-comment the inversion.
	// x = -x;
	// y = -y;

	// turn = -turn;
	// throttle = -throttle;

	// We want to increase the speed if we increase the throttle.
	x 	 *= throttle; 
	y 	 *= throttle;
	turn *= throttle;

	m_drive->drive(x,y,turn);
	// Robot::drive()
}

bool BackgroundDrive::IsFinished(){
	return false;
}

void BackgroundDrive::End(){}

void BackgroundDrive::Interrupted(){}