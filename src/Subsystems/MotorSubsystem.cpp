//*******************
// Golden Gears Robotics
// 11/22/14
// Wheel Motor Spin MAIN
//*******************

// 11-22-14 - Tyler Robbins - Created a file that declares the MotorSubsystem class and its methods.
// 12-11-14 - Tyler Robbins - Specified all methods (bar constructor/deconstructor) as void.

#include "MotorSubsystem.h"

#include "Commands/Subsystem.h"
#include "SpeedController.h"

#include "../Robot.h"

MotorSubsystem::MotorSubsystem(const char* name, SpeedController* motor, float power_up, float power_down)
	: Subsystem(name),
	m_name(name),
	m_motor(motor),
	m_power_up(power_up),
	m_power_down(power_down){

}

MotorSubsystem::~MotorSubsystem(){}

void MotorSubsystem::move(Direction dir){
	if (dir == Direction::UP)
		move(m_power_up);
	else if(dir == Direction::DOWN)
		move(m_power_down);
	else
		stop();
}

void MotorSubsystem::move(float power){
	m_motor->Set(power);
}

void MotorSubsystem::stop(){
	move(0.0);
}