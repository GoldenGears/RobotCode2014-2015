//*******************
// Golden Gears Robotics
// 11/23/14
// Background Drive H
// Runs by default when no other commands are running.
// Checks for joystick input first, then drives the Robot.
//*******************

// 11-23-14 - Tyler Robbins - Created a file that declares the BackgroundDrive class and its methods.
// 12-6-14 - Tyler Robbins - Added two new includes and a forward class declaration. isFinished no longer overrides. Constructor is now explicit. Removed empty curly brakets {}. Commented out m_joy.
// 12-11-14 - Tyler Robbins - Fixed method overrides. Fixed constructor declaration. 

#ifndef _COMMANDS_BACKGROUND_DRIVE_H_
#define _COMMANDS_BACKGROUND_DRIVE_H_ 

#include "Joystick.h"
#include "Commands/Command.h"

#include "../Subsystems/Drive.h"

class Drive;

class BackgroundDrive : public Command{
	public:
		BackgroundDrive(Drive *drive, Joystick *joy);
		~BackgroundDrive() override;

		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;

	private:
		Drive *m_drive;
		Joystick *m_joy;
};

#endif