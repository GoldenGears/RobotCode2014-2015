//***********************
// Golden Gears Robotics
// 11/6/14
// Config H
//***********************

// 11-6-14 - Tyler Robbins - Added a config file to store all configuration settings.
// 11-13-14 - Tyler Robbins - Added input constants.
// 12-6-14 - Tyler Robbins - Changed motor ports to allow for 6 motors (three on the left and three on the right). Added port numbers for the motors and joystick.

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG{
	namespace HARDWARE{
		// All hardware ports go here
		//    i.e: motors

		const int motorL1 = 1;
		const int motorL2 = 2;
		const int motorL3 = 3;
		const int motorR1 = 4;
		const int motorR2 = 5;
		const int motorR3 = 6;
	}

	namespace INPUT{
		// All input ports go here
		//    i.e: joystick buttons

		const int joystick1 = 1;

		const int bForward = 0; // These aren't used for anything currently, but they must be initialized anyway.
		const int bBackward = 0;
	}

	// Any additional namespaces and functions should go here.
}

#endif