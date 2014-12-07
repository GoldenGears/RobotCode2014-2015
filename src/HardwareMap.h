//************************
// Golden Gears Robotics
// 11/13/14
// Hardware Map H
//************************

// 11-13-14 - Tyler Robbins - Created a file to map all hardware to software objects.
// 12-6-14 - Tyler Robbins - Added an include. Added 6 Talon objects.

#ifndef _HARDWARE_MAP_H_
#define _HARDWARE_MAP_H_

#include "Talon.h"

class HardwareMap
{
public:
	HardwareMap();
	~HardwareMap();

	void init();

	// All Hardware variables go here

	// Drive Talons
	Talon left_1;
	Talon left_2;
	Talon left_3;

	Talon right_1;
	Talon right_2;
	Talon right_3;
};

#endif