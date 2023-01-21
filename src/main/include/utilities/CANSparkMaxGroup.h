// Inclusion guard
#ifndef CAN_SPARK_MAX_GROUP_H
#define CAN_SPARK_MAX_GROUP_H

// Included libraries
#include <vector>
#include <frc/Timer.h>
#include "rev/CANSparkMax.h"

/**
 * This class manages a group of CANSparkMax motor controllers
 * @author FIRST 171 - Cheese Curd Herd
 */
class CANSparkMaxGroup
{
private:
    /**
     * The vector storing the sparks in the group
     */
    std::vector<rev::CANSparkMax*> sparks;

    /**
     * The ramp rate of the group in ratio / sec
     */
    double rampRate;

    /**
     * The system clock timer
     */
    frc::Timer timer;

public:
    /**
     * Default constructor
     */
    CANSparkMaxGroup();

    /**
     * Parameterized constructor
     * @param sparks The CANSparkMax controllers for the motors
     * @param rampRate The ramp rate of the group
     */
    CANSparkMaxGroup(std::vector<rev::CANSparkMax*> sparks, double rampRate);

    /**
     * Copy constrctor
     * @param copy The CANSparkMaxGroup being copied
     */
    CANSparkMaxGroup(const CANSparkMaxGroup& copy);

    /**
     * Destructor
     */
    ~CANSparkMaxGroup();

    /**
     * Adds a CANSparkMax to the group
     * @param spark The CANSparkMax being added
     */
    void AddCANSparkMax(rev::CANSparkMax* spark);

    /**
     * Sets the ramp rate of the group in ratio / sec
     * @param rampRate The new ramp rate
     */
    void SetRampRate(double rampRate);

    /**
     * Sets the ratio of speed to use for the group (-1 - 1)
     * @param speed The speed being set
     */
    void Set(double speed);

    /**
     * Gets the ratio of speed being used for the group (-1 - 1)
     * @return The current speed ratio
     */
    double Get();

    /**
     * Disables the group
     */
    void Disable();

    /**
     * Stops the group until it is set again
     */
    void Stop();

    /**
     * Gets the position of the group in rotations
     * @return The position of the group in rotations
     */
    double GetPosition();

    /**
     * Gets the velocity of the group in RPM
     * @return The velocity of the group in RPM
     */
    double GetVelocity();

    /**
     * Sets the position of the group in rotations
     * @param position The new position of the group
     */
    void SetPosition(double position);

    /**
     * Sets the idle mode of the group (kCoast or kBrake)
     * @param idleMode The new idle mode
     */
    void SetIdleMode(rev::CANSparkMax::IdleMode idleMode);

    /**
     * Gets the idle mode of the group (kCoast or kBrake)
     * @return The idle mode of the group
     */
    rev::CANSparkMax::IdleMode GetIdleMode();

    /**
     * Assignment operator overload for CANSparkMaxGroup
     * @param rhs The CANSparkMaxGroup on the right hand side of the operator
     * @return This CANSparkMaxGroup with the assigned values
     */
    CANSparkMaxGroup& operator=(const CANSparkMaxGroup& rhs);
};

#endif