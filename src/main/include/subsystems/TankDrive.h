// Inclusion guard
#ifndef TANK_DRIVE_H
#define TANK_DRIVE_H

// Included headers
#include "utilities/CANSparkMaxGroup.h"
#include "utilities/DoubleSolenoidGroup.h"

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
     * The default ramp rate of the drive
     */
    const static double DEFAULT_RAMP_RATE = 4.0;

    /**
     * The motors on the drive
     */
    CANSparkMaxGroup leftMotors;
    CANSparkMaxGroup rightMotors;

    /**
     * The transmission on the drive
     */
    DoubleSolenoidGroup transmission;

    /**
     * The ramp rate for each gear
     */
    double highRampRate;
    double lowRampRate;

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
     * Parameterized constructor
     * @param leftMotors The left motor group
     * @param rightMotors The right motor group
     * @param transmission The transmission solenoids
     */
    TankDrive(CANSparkMaxGroup leftMotors, CANSparkMaxGroup rightMotors, DoubleSolenoidGroup transmission);

    /**
     * Copy constructor
     * @param copy The tank drive being copied
     */
    TankDrive(const TankDrive& copy);

    /**
     * Destructor
     */
    ~TankDrive();

    /**
     * Adds a motor to the left side of the drive
     * @param motor The motor being added
     */
    void addLeftMotor(rev::CANSparkMax* motor);
    
    /**
     * Adds a motor to the right side of the drive
     * @param motor The motor being added
     */
    void addRightMotor(rev::CANSparkMax* motor);

    /**
     * Adds a solenoid to the transmission
     * @param solenoid The solenoid being added
     */
    void addTransmissionSolenoid(frc::DoubleSolenoid* solenoid);

    /**
     * Sets the ramp rate of the drive
     * @param highRampRate The ramp rate of the drive in high gear
     * @param lowRampRate The ramp rate of the drive in low gear
     */
    void setRampRate(double highRampRate, double lowRampRate = DEFAULT_RAMP_RATE);

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

    /**
     * Assignment operator overload for TankDrive
     * @param rhs The TankDrive object on the right hand side of the operator
     * @return This TankDrive with the assigned values
     */
    TankDrive& operator=(const TankDrive& rhs);
};

#endif