//*******************
// Golden Gears Robotics
// 11/22/14
// Wheel Motor Spin H
//*******************

// 11-22-14 - Tyler Robbins - Created a file that defines the WheelMotorSpin class which will be used as a command for turning the arm wheels.

#ifndef _COMMANDS_WHEEL_MOTOR_SPIN_H
#define _COMMANDS_WHEEL_MOTOR_SPIN_H

#include "Commands/Command.h"

#include "../Robot.h"

class WheelMotorSpin : public Command {
 public:
	explicit WheelMotorSpin(Direction dir);
	~WheelMotorSpin() override;

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

 private:
 	Direction m_direct;
};

#endif