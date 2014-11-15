//***********************
// Golden Gears Robotics
// 11/6/14
// Config H
//***********************

// 11-6-14 - Tyler Robbins - Added a config file to store all configuration settings.
// 11-13-14 - Tyler Robbins - Added input constants.

#ifndef _CONFIG_H_
#define _CONFIG_H_

namespace CONFIG{
	namespace HARDWARE{
		// All hardware ports go here
		//    i.e: motors

		const int motorL;
		const int motorR;
	}

	namespace INPUT{
		// All input ports go here
		//    i.e: joystick buttons

		const int joystick1;

		const int bForward;
		const int bBackward;
	}

	// Any additional namespaces and functions should go here.
}

#endif