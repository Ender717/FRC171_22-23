// Included headers
#include "utilities/DoubleSolenoidGroup.h"

DoubleSolenoidGroup::DoubleSolenoidGroup()
{
    
}

DoubleSolenoidGroup::DoubleSolenoidGroup(std::vector<frc::DoubleSolenoid*> doubleSolenoids)
{
    this->doubleSolenoids.assign(doubleSolenoids.begin(), doubleSolenoids.end());
}

DoubleSolenoidGroup::DoubleSolenoidGroup(const DoubleSolenoidGroup& copy)
{
    doubleSolenoids.assign(copy.doubleSolenoids.begin(), copy.doubleSolenoids.end());
}

DoubleSolenoidGroup::~DoubleSolenoidGroup()
{
    for (frc::DoubleSolenoid* doubleSolenoid : doubleSolenoids)
        delete doubleSolenoid;
}

void DoubleSolenoidGroup::AddDoubleSolenoid(frc::DoubleSolenoid* doubleSolenoid)
{
    if (doubleSolenoid != nullptr)
        doubleSolenoids.push_back(doubleSolenoid);
}

void DoubleSolenoidGroup::Set(frc::DoubleSolenoid::Value value)
{
    for (frc::DoubleSolenoid* doubleSolenoid : doubleSolenoids)
        if (doubleSolenoid != nullptr)
            doubleSolenoid->Set(value);
}

frc::DoubleSolenoid::Value DoubleSolenoidGroup::Get()
{
    for (frc::DoubleSolenoid* doubleSolenoid : doubleSolenoids)
        if (doubleSolenoid != nullptr)
            return doubleSolenoid->Get();
    return frc::DoubleSolenoid::Value::kOff;
}

DoubleSolenoidGroup& DoubleSolenoidGroup::operator=(const DoubleSolenoidGroup& rhs)
{
    for (frc::DoubleSolenoid* doubleSolenoid : doubleSolenoids)
        delete doubleSolenoid;
    doubleSolenoids.clear();
    doubleSolenoids.assign(rhs.doubleSolenoids.begin(), rhs.doubleSolenoids.end());
    return *this;
}