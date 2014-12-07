//************************
// Golden Gears Robotics
// 10/30/14
// Input Objects MAIN
//************************

//11-13-14 - Tyler Robbins - Created a OI.cpp file to define all input objects in OI.h
//12-6-14 - Tyler Robbins - Added missing semicolons. Fixed member initializer list.

#include "OI.h"

#include "Robot.h"
#include "Config.h"

#include "Commands/WheelMotorSpin.h" // <- This still needs to be added

OI::OI()
	: joy(CONFIG::INPUT::joystick1),
	wheelBackward(&joy,CONFIG::INPUT::bBackward),
	wheelForward(&joy,CONFIG::INPUT::bForward)
	{ }

OI::~OI(){ }

void OI::init(){
	// Wire buttons, joysticks, and SmartDashboard controls to commands

	wheelForward.WhileHeld(new WheelMotorSpin(Direction::UP));
	wheelBackward.WhileHeld(new WheelMotorSpin(Direction::DOWN));

}