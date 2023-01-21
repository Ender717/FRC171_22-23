// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive() 
{ 
    rev::CANSparkMax left1Motor{1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax left2Motor{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax left3Motor{3, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax right1Motor{4, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax right2Motor{5, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax right3Motor{6, rev::CANSparkMax::MotorType::kBrushless};
    double RAMP_RATE = 1.0;

    left1Motor.SetInverted(false);
    left2Motor.SetInverted(false);
    left3Motor.SetInverted(false);
    right1Motor.SetInverted(true);
    right2Motor.SetInverted(true);
    right3Motor.SetInverted(true);

    leftSparks.AddCANSparkMax(&left1Motor);
    leftSparks.AddCANSparkMax(&left2Motor);
    leftSparks.AddCANSparkMax(&left3Motor);
    rightSparks.AddCANSparkMax(&right1Motor);
    rightSparks.AddCANSparkMax(&right2Motor);
    rightSparks.AddCANSparkMax(&right3Motor);

    leftSparks.SetRampRate(RAMP_RATE);
    rightSparks.SetRampRate(RAMP_RATE);
}

void ArcadeDrive::Move(double leftPower, double rightPower)
{
    if (std::abs(leftPower) < 0.04)
        leftPower = 0.0;
    if (std::abs(rightPower) < 0.04)
        rightPower = 0.0;

    leftSparks.Set(leftPower);
    rightSparks.Set(rightPower);
}

void ArcadeDrive::SwitchGears()
{
    leftPiston.Toggle();
    rightPiston.Toggle();
}

void ArcadeDrive::Periodic() 
{
    // Implementation of subsystem periodic method goes here.
}

void ArcadeDrive::SimulationPeriodic() 
{
    // Implementation of subsystem simulation periodic method goes here.
}
