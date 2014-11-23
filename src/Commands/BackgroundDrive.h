//*******************
// Golden Gears Robotics
// 11/23/14
// Background Drive H
// Runs by default when no other commands are running.
// Checks for joystick input first, then drives the Robot.
//*******************

// 11-23-14 - Tyler Robbins - Created a file that defines the BackgroundDrive class and its methods.

#ifndef _COMMANDS_BACKGROUND_DRIVE_H_
#define _COMMANDS_BACKGROUND_DRIVE_H_ 

#include "Commands/Command.h"

class BackgroundDrive : public Command{
public:
	BackgroundDrive(Drive *drive, Joystick *joy);
	~BackgroundDrive() override;

	void Initialize(){} override;
	void Execute(){} override;
	void isFinished(){} override;
	void End(){} override;
	void Interrupted(){} override;

private:
	Drive *m_drive;
	Joystick *m_joy;
};

#endif