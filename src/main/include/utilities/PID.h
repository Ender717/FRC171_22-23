// Inclusion guard
#ifndef PID_H
#define PID_H

// Included libraries
#include <frc/Timer.h>

/**
 * This class manages a PID controller
 * @author FRC Team 171 - Cheese Curd Herd
 */
class PID
{
private:
    /**
     * Control constants
     */
    double kp;
    double ki;
    double kd;

    /**
     * Saturation limit for integral
     */
    double ks;  

    /**
     * The timer to track loop length
     */
    frc::Timer timer;

    /**
     * The current integral value
     */
    double integral;

    /**
     * Data from past loop
     */
    double pastError;

    /**
     * Target value
     */
    double target;

    /**
     * Gets the proportional component of the control value
     * @param error The current error
     * @return The proportional component
     */
    double getProportional(double error);

    /**
     * Gets the integral component of the control value
     * @param error The current error
     * @param loopTime The time spent inbetween loops
     * @return The integral component
     */
    double getIntegral(double error, double loopTime);

    /**
     * Gets the derivative component of the control value
     * @param error The current error
     * @param loopTime The time spent inbetween loops
     * @return The derivative component
     */
    double getDerivative(double error, double loopTime);

public:
    /**
     * Default constructor
     */
    PID();

    /**
     * Parameterized constructor
     * @param kp The proportional control constant
     * @param ki The integral control constant
     * @param kd The derivative control constant
     * @param ks The integral saturation limit
     */
    PID(double kp, double ki, double kd, double ks);

    /**
     * Copy constructor
     * @param copy The PID controller being copied
     */
    PID(const PID& copy);

    /**
     * Destructor
     */
    ~PID();

    /**
     * Sets the target of the PID controller
     * @param target The new target
     */
    void setTarget(double target);

    /**
     * Gets the control value for the current value
     * @param current The current system value
     * @return The corresponding control value
     */
    double getValue(double current);

    /**
     * Assignment operator overload for PID
     * @param rhs The PID object on the right hand side of the operator
     * @return This PID with the assigned values
     */
    PID& operator=(const PID& rhs);
};

#endif