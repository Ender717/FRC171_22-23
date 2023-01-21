// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Solenoid.h>
#include "utilities/CANSparkMaxGroup.h"

class ArcadeDrive : public frc2::SubsystemBase 
{
private:
    /**
     * The left and right drive motor groups
     */
    CANSparkMaxGroup leftSparks;
    CANSparkMaxGroup rightSparks;
    frc::Solenoid leftPiston{frc::PneumaticsModuleType::CTREPCM, 1};
    frc::Solenoid rightPiston{frc::PneumaticsModuleType::CTREPCM, 2};

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
     * Switches the gears of the drive
     */
    void SwitchGears();

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
