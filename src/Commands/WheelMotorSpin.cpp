//*******************
// Golden Gears Robotics
// 11/22/14
// Wheel Motor Spin MAIN
//*******************

// 11-22-14 - Tyler Robbins - Created a file that declares the WheelMotorSpin class and its methods.
// 12-6-14 - Tyler Robbins - Removed Requires statement in constructor. Commented out code for the Execute, End, and Interrupted methods. Fixed capitalization of the IsFinished method.

#include "WheelMotorSpin.h"

#include "../Subsystems/MotorSubsystem.h"

#include "../Config.h"
#include "../Robot.h"

WheelMotorSpin::WheelMotorSpin(Direction dir)
	: Command("WheelMotorSpin"),
	m_direct(dir) {
	// Requires(Robot::arm_wheels());
}

WheelMotorSpin::~WheelMotorSpin() {}

void WheelMotorSpin::Initialize() {}

void WheelMotorSpin::Execute() {
	// Robot::arm_wheels()->move(m_direct);
}

bool WheelMotorSpin::IsFinished() {
	return false;
}

void WheelMotorSpin::End() {
	// Robot::arm_wheels()->stop();
}

void WheelMotorSpin::Interrupted() {
	// Robot::arm_wheels()->stop();
}