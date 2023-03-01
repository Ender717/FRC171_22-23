// Included headers
#include "subsystems/TankDrive.h"

TankDrive::TankDrive()
{
    gear = Gear::HIGH;
}

void TankDrive::initialize()
{
    // Invert the right motors
    rightMotor1.SetInverted(true);
    rightMotor2.SetInverted(true);
    rightMotor3.SetInverted(true);
    
    // Set the motors to brake
    leftMotor1.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    leftMotor2.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    leftMotor3.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightMotor1.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightMotor2.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightMotor3.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    // Put the transmission in high gear
    transmissionPiston1.Set(frc::DoubleSolenoid::Value::kForward);
}

void TankDrive::move(double left, double right)
{
    leftMotor1.Set(left);
    leftMotor2.Set(left);
    leftMotor3.Set(left);
    rightMotor1.Set(right);
    rightMotor2.Set(right);
    rightMotor3.Set(right);
}

void TankDrive::setGear(Gear gear)
{
    this->gear = gear;
    switch(gear)
    {
        case Gear::LOW:
            transmissionPiston1.Set(frc::DoubleSolenoid::Value::kReverse);
            break;
        case Gear::HIGH:
            transmissionPiston1.Set(frc::DoubleSolenoid::Value::kForward);
            break;
        case Gear::NEUTRAL:
            transmissionPiston1.Set(frc::DoubleSolenoid::Value::kOff);
            leftMotor1.StopMotor();
            leftMotor2.StopMotor();
            leftMotor3.StopMotor();
            rightMotor1.StopMotor();
            rightMotor2.StopMotor();
            rightMotor3.StopMotor();
            break;
    }
}

Gear TankDrive::getGear()
{
    return gear;
}