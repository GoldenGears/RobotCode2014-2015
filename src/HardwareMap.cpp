//************************
// Golden Gears Robotics
// 10/30/14
// Hardware Map MAIN
//************************

//11-13-14 - Tyler Robbins - Created a HardwareMap.cpp file to define everything that is declared in HardwareMap.h
//12-6-14 - Tyler Robbins - Added an include. Added items for the member initializer list.

#include "HardwareMap.h"

#include "Config.h"

HardwareMap::HardwareMap()
	: left_1(CONFIG::HARDWARE::motorL1),
	left_2(CONFIG::HARDWARE::motorL2),
	left_3(CONFIG::HARDWARE::motorL3),
	right_1(CONFIG::HARDWARE::motorR1),
	right_2(CONFIG::HARDWARE::motorR2),
	right_3(CONFIG::HARDWARE::motorR3){

}

HardwareMap::~HardwareMap(){ }

void HardwareMap::init(){ }