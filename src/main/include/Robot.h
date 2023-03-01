// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include "subsystems/TankDrive.h"

class Robot : public frc::TimedRobot 
{
private:
    frc::XboxController controller{0};
    TankDrive tankDrive;
    rev::CANSparkMax intakeLeft{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax intakeRight{8, rev::CANSparkMax::MotorType::kBrushless};
    double leftZeroX;
    double leftZeroY;
    double rightZeroX;
    double rightZeroY;

public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
    void SimulationInit() override;
    void SimulationPeriodic() override;
};