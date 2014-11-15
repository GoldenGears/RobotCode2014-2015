//************************
// Golden Gears Robotics
// 10/30/14
// Input Objects H
//************************

//11-13-14 - Tyler Robbins - Created a file to declare input objects such as Joysticks and JoystickButtons

#ifndef _OI_H_
#define _OI_H_

#include "Joystick.h"
#include "Buttons/JoystickButton.h"

class OI
{
public:
	OI();
	~OI();

	void init();

	Joystick joy;

	JoystickButton wheelBackward;
	JoystickButton wheelForward;
};

#endif