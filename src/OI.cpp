//************************
// Golden Gears Robotics
// 10/30/14
// Input Objects MAIN
//************************

//11-13-14 - Tyler Robbins - Created a OI.cpp file to define all input objects in OI.h

#include "OI.h"

#include "Robot.h"
#include "Config.h"

#include "Commands/WheelMotorSpin.h" // <- This still needs to be added

OI::OI()
	: joystick(CONFIG::INPUT::joystick1),
	wheelBackward(&joystick,CONFIG::INPUT::bBackward),
	wheelForward(&joystick,CONFIG::INPUT::bForward)
	{ }

OI::~OI(){ }

void OI::init(){
	// Wire buttons, joysticks, and SmartDashboard controls to commands

	//TODO: Add WheelMotorSpin class
	wheelForward.whileHeld(new WheelMotorSpin(Direction::UP))
	wheelBackward.whileHeld(new WheelMotorSpin(Direction::DOWN))

}