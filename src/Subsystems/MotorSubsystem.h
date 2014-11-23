//*******************
// Golden Gears Robotics
// 11/23/14
// Motor Subsystem H
//*******************

// 11-23-14 - Tyler Robbins - Created a file that defines the MotorSubsystem class.

#ifndef _SUBSYSTEMS_MOTOR_SUBSYSTEM_H_
#define _SUBSYSTEMS_MOTOR_SUBSYSTEM_H_

#include "Commands/Subsystem.h"

#include "../Robot.h"

class MotorSubsystem : public Subsystem
{
public:
	MotorSubsystem(const char* name, SpeedController* motor, float power_up = 1.0, float power_down = -1.0);
	~MotorSubsystem() override;

	void move(Direction dir); //Move in a specified direction

	void move(float power); //Move with a specified power

	void stop();

private:
	const char* m_name;
	SpeedController* m_motor;
	float m_power_up;
	float m_power_down;
};

#endif