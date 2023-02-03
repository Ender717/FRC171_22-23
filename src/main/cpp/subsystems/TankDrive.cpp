// Included headers
#include "subsystems/TankDrive.h"

TankDrive::TankDrive()
{
    highRampRate = DEFAULT_RAMP_RATE;
    lowRampRate = DEFAULT_RAMP_RATE;
    gear = Gear::HIGH;
}

TankDrive::TankDrive(CANSparkMaxGroup leftMotors, CANSparkMaxGroup rightMotors, DoubleSolenoidGroup transmission)
{
    this->leftMotors = leftMotors;
    this->rightMotors = rightMotors;
    this->transmission = transmission;
    highRampRate = DEFAULT_RAMP_RATE;
    lowRampRate = DEFAULT_RAMP_RATE;
    gear = Gear::HIGH;
}

TankDrive::TankDrive(const TankDrive& copy)
{
    leftMotors = copy.leftMotors;
    rightMotors = copy.rightMotors;
    transmission = copy.transmission;
    highRampRate = copy.highRampRate;
    lowRampRate = copy.lowRampRate;
    gear = copy.gear;
}

TankDrive::~TankDrive()
{

}

void TankDrive::addLeftMotor(rev::CANSparkMax* motor)
{
    leftMotors.AddCANSparkMax(motor);
}

void TankDrive::addRightMotor(rev::CANSparkMax* motor)
{
    rightMotors.AddCANSparkMax(motor);
}

void TankDrive::addTransmissionSolenoid(frc::DoubleSolenoid* solenoid)
{
    transmission.AddDoubleSolenoid(solenoid);
}

void TankDrive::setRampRate(double highRampRate, double lowRampRate = DEFAULT_RAMP_RATE)
{
    this->highRampRate = highRampRate;
    this->lowRampRate = lowRampRate;
}

void TankDrive::initialize()
{
    // Set the motors to brake
    leftMotors.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    rightMotors.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    // Put the transmission in high gear
    transmission.Set(frc::DoubleSolenoid::Value::kForward);
}

void TankDrive::move(double left, double right)
{
    leftMotors.Set(left);
    rightMotors.Set(right);
}

void TankDrive::setGear(Gear gear)
{
    this->gear = gear;
    switch(gear)
    {
        case Gear::LOW:
            leftMotors.SetRampRate(lowRampRate);
            rightMotors.SetRampRate(lowRampRate);
            transmission.Set(frc::DoubleSolenoid::Value::kReverse);
            break;
        case Gear::HIGH:
            leftMotors.SetRampRate(highRampRate);
            rightMotors.SetRampRate(highRampRate);
            transmission.Set(frc::DoubleSolenoid::Value::kForward);
            break;
        case Gear::NEUTRAL:
            leftMotors.Stop();
            rightMotors.Stop();
            leftMotors.SetRampRate(0.0);
            rightMotors.SetRampRate(0.0);
            transmission.Set(frc::DoubleSolenoid::Value::kOff);
            break;
    }
}

Gear TankDrive::getGear()
{
    return gear;
}

TankDrive& TankDrive::operator=(const TankDrive& rhs)
{
    leftMotors = rhs.leftMotors;
    rightMotors = rhs.rightMotors;
    transmission = rhs.transmission;
    highRampRate = rhs.highRampRate;
    lowRampRate = rhs.lowRampRate;
    gear = rhs.gear;

    return *this;
}