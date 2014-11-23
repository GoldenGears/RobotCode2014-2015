//*******************
// Golden Gears Robotics
// 11/23/14
// Background Drive MAIN
//*******************

// 11-23-14 - Tyler Robbins - Created a file that declares the BackgroundDrive class and its methods.

#include "BackgroundDrive.h"
#include "Joystick.h"

#include "../Subsystems/Drive.h"

BackgroundDrive::BackgroundDrive(Drive *drive, Joystick *joy)
	: Command("BackgroundDrive"),
	m_drive(drive),
	m_joy(joy) {
		Requires(drive);
}

BackgroundDrive::~BackgroundDrive(){}

BackgroundDrive::Initialize(){}

BackgroundDrive::Execute(){
	float x,y,turn,throttle;

	x = m_joy->GetX();
	y = m_joy->GetY();

	turn = m_joy->GetThrottle(); // For some wierd reason, these are swapped according to last year's code.
	throttle = m_joy->GetTwist(); // We should test this just to be sure though.

	// Add 1 to shift the values and then divide by 2 to scale down
	throttle = (-throttle + 1.0)/2.0; // Note: Not sure why this is necessary. Should contact Philip or Matt and ask them.

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
}

BackgroundDrive::isFinished(){
	return false;
}

BackgroundDrive::End(){}

BackgroundDrive::Interrupted(){}