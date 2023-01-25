// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() 
{
    rev::CANSparkMax* left1 = new rev::CANSparkMax{1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* left2 = new rev::CANSparkMax{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* left3 = new rev::CANSparkMax{3, rev::CANSparkMax::MotorType::kBrushless};
    testLeft.AddCANSparkMax(left1);
    testLeft.AddCANSparkMax(left2);
    testLeft.AddCANSparkMax(left3);
    testLeft.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    testLeft.SetRampRate(4.0);

    rev::CANSparkMax* right1 = new rev::CANSparkMax{4, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* right2 = new rev::CANSparkMax{5, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax* right3 = new rev::CANSparkMax{6, rev::CANSparkMax::MotorType::kBrushless};
    testRight.AddCANSparkMax(right1);
    testRight.AddCANSparkMax(right2);
    testRight.AddCANSparkMax(right3);
    testRight.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    testRight.SetRampRate(4.0);

    frc::DoubleSolenoid* transmission1 = new frc::DoubleSolenoid{frc::PneumaticsModuleType::CTREPCM, 0, 1};
    testTransmission.AddDoubleSolenoid(transmission1);
    testTransmission.Set(frc::DoubleSolenoid::kForward);
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
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (m_autonomousCommand != nullptr) 
    {
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() 
{
    double left = controller.GetLeftY() - controller.GetRightX();
    double right = controller.GetLeftY() + controller.GetRightX();

    if (std::abs(left) < 0.08)
        left = 0;
    if (std::abs(right) < 0.08)
        right = 0;

    testLeft.Set(left);
    testRight.Set(right);

    if (controller.GetRightBumperPressed())
    {
        if (testTransmission.Get() == frc::DoubleSolenoid::kForward)
            testTransmission.Set(frc::DoubleSolenoid::kReverse);
        else
            testTransmission.Set(frc::DoubleSolenoid::kForward);
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