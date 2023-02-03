// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() 
{
    // Create the left side of the drive
    CANSparkMaxGroup driveLeftMotors;
    rev::CANSparkMax* left1 = new rev::CANSparkMax{1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* left2 = new rev::CANSparkMax{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* left3 = new rev::CANSparkMax{3, rev::CANSparkMax::MotorType::kBrushless};
    driveLeftMotors.AddCANSparkMax(left1);
    driveLeftMotors.AddCANSparkMax(left2);
    driveLeftMotors.AddCANSparkMax(left3);
    driveLeftMotors.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    driveLeftMotors.SetRampRate(4.0);

    // Create the right side of the drive
    CANSparkMaxGroup driveRightMotors;
    rev::CANSparkMax* right1 = new rev::CANSparkMax{4, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* right2 = new rev::CANSparkMax{5, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* right3 = new rev::CANSparkMax{6, rev::CANSparkMax::MotorType::kBrushless};
    driveRightMotors.AddCANSparkMax(right1);
    driveRightMotors.AddCANSparkMax(right2);
    driveRightMotors.AddCANSparkMax(right3);
    driveRightMotors.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    driveRightMotors.SetRampRate(4.0);

    // Create the transmission of the drive
    DoubleSolenoidGroup driveTransmission;
    frc::DoubleSolenoid* transmission1 = new frc::DoubleSolenoid{frc::PneumaticsModuleType::CTREPCM, 0, 1};
    driveTransmission.AddDoubleSolenoid(transmission1);
    driveTransmission.Set(frc::DoubleSolenoid::kForward);

    // Create the tankDrive
    tankDrive = new TankDrive(driveLeftMotors, driveRightMotors, driveTransmission);
    tankDrive->setRampRate(4.0, 8.0);
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
    if (tankDrive != nullptr)
    {
        double left = controller.GetLeftY() - controller.GetRightX();
        double right = controller.GetLeftY() + controller.GetRightX();

        if (std::abs(left) < 0.08)
            left = 0;
        if (std::abs(right) < 0.08)
            right = 0;

        tankDrive->move(left, right);

        if (controller.GetRightBumperPressed())
        {
            if (tankDrive->getGear() == Gear::HIGH)
                tankDrive->setGear(Gear::LOW);
            else
                tankDrive->setGear(Gear::HIGH);
        }
    }
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