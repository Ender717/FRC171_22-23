// Inclusion guard
#ifndef TANK_DRIVE_H
#define TANK_DRIVE_H

// Included libraries
#include <frc/DoubleSolenoid.h>>

// Included headers
#include "rev/CANSparkMax.h"


/**
 * This is an enum for the different gears available on the drive
 */
enum class Gear
{
    LOW,
    HIGH,
    NEUTRAL
};

/**
 * This class manages a tank drive subsystem
 * @author FRC 171 - Cheese Curd Herd
 */
class TankDrive
{
private:
    /**
     * The motors for the drive
     */
    rev::CANSparkMax leftMotor1{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax leftMotor2{8, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax leftMotor3{9, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rightMotor1{4, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rightMotor2{5, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rightMotor3{6, rev::CANSparkMax::MotorType::kBrushless};

    /**
     * The solenoids for the transmission
     */
    frc::DoubleSolenoid transmissionPiston1{1, frc::PneumaticsModuleType::REVPH, 0, 1};

    /**
     * Which gear the drive is currently in
     */
    Gear gear;

public:
    /**
     * Default constructor
     */
    TankDrive();

    /**
     * Initializes the tank drive
     */
    void initialize();

    /**
     * Moves the tank drive
     * @param left The power to send to the left motors
     * @param right The power to send to the right motors
     */
    void move(double left, double right);

    /**
     * Sets the drive gearing
     * @param gear The gear to set
     */
    void setGear(Gear gear);

    /**
     * Gets the current drive gearing
     * @return The current gear
     */
    Gear getGear();
};

#endif