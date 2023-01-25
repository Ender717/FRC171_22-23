// Inclusion guard
#ifndef SOLENOID_GROUP_H
#define SOLENOID_GROUP_H

// Included libraries
#include <vector>
#include <frc/Solenoid.h>

/**
 * This class manages a group of solenoids
 * @author FRC 171 - Cheese Curd Herd
 */
class SolenoidGroup
{
private:
    /**
     * The solenoids in the group
     */
    std::vector<frc::Solenoid*> solenoids;
    
    /**
     * Whether the solenoids are set or not
     */
    bool set;

public:
    /**
     * Default constructor
     */
    SolenoidGroup();

    /**
     * Parameterized constructor
     * @param solenoids The solenoids for the group
     */
    SolenoidGroup(std::vector<frc::Solenoid*> solenoids);

    /**
     * Copy constructor
     * @param copy The group being copied
     */
    SolenoidGroup(const SolenoidGroup& copy);

    /**
     * Destructor
     */
    ~SolenoidGroup();

    /**
     * Adds a solenoid to the group
     * @param solenoid The solenoid being added
     */
    void AddSolenoid(frc::Solenoid* solenoid);

    /**
     * Sets the solenoids in the group
     * @param set The set boolean being used
     */
    void Set(bool set);

    /**
     * Toggles the solenoids in the group
     */
    void Toggle();

    /**
     * Checks if the solenoids are set
     * @return True if the solenoids are set, false if not
     */
    bool AreSet();

    /**
     * Assignment operator overload for SolenoidGroup
     * @param rhs The SolenoidGroup on the right hand side of the operator
     * @return This SolenoidGroup with the assigned values
     */
    SolenoidGroup& operator=(const SolenoidGroup& rhs);
};

#endif