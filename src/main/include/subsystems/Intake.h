// Inclusion guard
#ifndef INTAKE_H
#define INTAKE_H

// Included headers
#include "rev/CANSparkMax.h"

/**
 * This class manages an intake subsystem
 * @author FRC 171 - Cheese Curd Herd
 */
class Intake
{
private:
    /**
     * The motors for the intake
     */
    rev::CANSparkMax leftMotor1{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rightMotor1{3, rev::CANSparkMax::MotorType::kBrushless};

public:
    /**
     * Default constructor
     */
    Intake();

    /**
     * Initializes the tank drive
     */
    void initialize();

    /**
     * Moves the intake
     * @param power The power to send to the intake motors
     */
    void move(double power);
};

#endif