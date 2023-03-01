// Included headers
#include "subsystems/Intake.h"

Intake::Intake()
{

}

void Intake::initialize()
{
    // Invert the right motors
    rightMotor1.SetInverted(true);

    // Set the motors to brake
    leftMotor1.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightMotor1.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

void Intake::move(double power)
{
    leftMotor1.Set(power);
    rightMotor1.Set(power);
}