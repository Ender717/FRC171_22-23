// Inclusion guard
#ifndef TANK_DRIVE_H
#define TANK_DRIVE_H

// Included headers
#include "utilities/CANSparkMaxGroup.h"
#include "utilities/DoubleSolenoidGroup.h"

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
    const double RAMP_RATE = 0.5;

    /**
     * The motors on the drive
     */
    CANSparkMaxGroup leftMotors;
    CANSparkMaxGroup rightMotors;

    /**
     * The transmission on the drive
     */
    DoubleSolenoidGroup transmission;

public:
    
};

#endif