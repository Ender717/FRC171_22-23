// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Timer.h>
#include "rev/CANSparkMax.h"

class ArcadeDrive : public frc2::SubsystemBase 
{
private:
    const double RAMP_RATE = 1.0;
    
    rev::CANSparkMax rightFrontMotor{1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rightRearMotor{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax leftFrontMotor{3, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax leftRearMotor{4, rev::CANSparkMax::MotorType::kBrushless};

    double leftPower;
    double rightPower;
    frc::Timer timer;

public:
    /**
     * Default constructor for ArcadeDrive
     */
    ArcadeDrive();

    /** 
     * Moves the drive using the designated power levels
     */
    void Move(double leftPower, double rightPower);

    /**
     * Will be called periodically whenever the CommandScheduler runs.
     */
    void Periodic() override;

    /**
     * Will be called periodically whenever the CommandScheduler runs during
     * simulation.
     */
    void SimulationPeriodic() override;
};
