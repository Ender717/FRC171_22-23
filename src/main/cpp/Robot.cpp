// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() 
{
    // Initialize the drive
    tankDrive.initialize();

    // Set the controller zero position
    leftZeroX = controller.GetLeftX();
    leftZeroY = controller.GetLeftY();
    rightZeroX = controller.GetRightX();
    rightZeroY = controller.GetRightY();
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() 
{
    frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() 
{

}

void Robot::DisabledPeriodic() 
{

}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() 
{
    
}

void Robot::AutonomousPeriodic() 
{

}

void Robot::TeleopInit() 
{
    
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() 
{
    double leftDrivePower = (controller.GetLeftY() - leftZeroY) - (controller.GetRightX() - rightZeroX);
    double rightDrivePower = (controller.GetLeftY() - leftZeroY) + (controller.GetRightX() - rightZeroX);

    tankDrive.move(leftDrivePower, rightDrivePower);

    if (controller.GetRightBumperPressed())
    {
        if (tankDrive.getGear() == Gear::HIGH)
            tankDrive.setGear(Gear::LOW);
        else
            tankDrive.setGear(Gear::HIGH);
    }

    double intakePower = controller.GetLeftTriggerAxis() - controller.GetRightTriggerAxis();
    intake.move(intakePower);
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() 
{

}

/**
 * This function is called once when the robot is first started up.
 */
void Robot::SimulationInit() 
{

}

/**
 * This function is called periodically whilst in simulation.
 */
void Robot::SimulationPeriodic() 
{

}

#ifndef RUNNING_FRC_TESTS
int main() 
{
    return frc::StartRobot<Robot>();
}
#endif