// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive() 
{
    leftFrontMotor.SetInverted(false);
    leftRearMotor.SetInverted(false);
    rightFrontMotor.SetInverted(true);
    rightRearMotor.SetInverted(true);

    leftPower = 0.0;
    rightPower = 0.0;
    timer.Start();
}

void ArcadeDrive::Move(double leftPower, double rightPower)
{
    units::second_t loopTime = timer.Get();
    timer.Reset();

    if (std::abs(leftPower) < 0.04)
        leftPower = 0.0;
    if (std::abs(rightPower) < 0.04)
        rightPower = 0.0;

    leftPower *= 0.5;
    rightPower *= 0.5;

    if ((std::abs(leftPower) - std::abs(this->leftPower)) / loopTime.value() > RAMP_RATE)
        leftPower = this->leftPower + (leftPower / std::abs(leftPower)) * RAMP_RATE * loopTime.value();
    if ((std::abs(rightPower) - std::abs(this->rightPower)) / loopTime.value() > RAMP_RATE)
        rightPower = this->rightPower + (rightPower / std::abs(rightPower)) * RAMP_RATE * loopTime.value();
    
    this->leftPower = leftPower;
    this->rightPower = rightPower;

    leftFrontMotor.Set(leftPower);
    leftRearMotor.Set(leftPower);
    rightFrontMotor.Set(rightPower);
    rightRearMotor.Set(rightPower);
}

void ArcadeDrive::Periodic() 
{
    // Implementation of subsystem periodic method goes here.
}

void ArcadeDrive::SimulationPeriodic() 
{
    // Implementation of subsystem simulation periodic method goes here.
}
