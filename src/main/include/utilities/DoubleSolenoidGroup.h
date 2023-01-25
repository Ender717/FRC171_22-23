// Inclusion guard
#ifndef DOUBLE_SOLENOID_GROUP_H
#define DOUBLE_SOLENOID_GROUP_H

// Included libraries
#include <vector>
#include <frc/DoubleSolenoid.h>


/**
 * This class manages a group of doublesolenoids
 * @author FRC 171 - Cheese Curd Herd
 */
class DoubleSolenoidGroup
{
private:
    /**
     * The doublesolenoids in the group
     */
    std::vector<frc::DoubleSolenoid*> doubleSolenoids;

public:
    /**
     * Default constructor
     */
    DoubleSolenoidGroup();

    /**
     * Parameterized constructor
     * @param doubleSolenoids The doublesolenoids for the group
     */
    DoubleSolenoidGroup(std::vector<frc::DoubleSolenoid*> doubleSolenoids);

    /**
     * Copy constructor
     * @param copy The group being copied
     */
    DoubleSolenoidGroup(const DoubleSolenoidGroup& copy);

    /**
     * Destructor
     */
    ~DoubleSolenoidGroup();

    /**
     * Adds a doublesolenoid to the group
     * @param doubleSolenoid The doublesolenoid being added
     */
    void AddDoubleSolenoid(frc::DoubleSolenoid* doubleSolenoid);

    /**
     * Sets the doublesolenoids in the group
     * @param value The value being used
     */
    void Set(frc::DoubleSolenoid::Value value);

    /**
     * Gets the value of the doublesolenoids
     * @return The value of the doublesolenoids
     */
    frc::DoubleSolenoid::Value Get();

    /**
     * Assignment operator overload for DoubleSolenoidGroup
     * @param rhs The DoubleSolenoidGroup on the right hand side of the operator
     * @return This DoubleSolenoidGroup with the assigned values
     */
    DoubleSolenoidGroup& operator=(const DoubleSolenoidGroup& rhs);
};

#endif