// Included header
#include "utilities/CANSparkMaxGroup.h"

CANSparkMaxGroup::CANSparkMaxGroup()
{
    rampRate = 1.0;
    timer.Start();
}

CANSparkMaxGroup::CANSparkMaxGroup(std::vector<rev::CANSparkMax*> sparks, double rampRate)
{
    for (uint32_t i = 0; i < sparks.size(); i++)
        this->sparks.push_back(sparks[i]);
    this->rampRate = rampRate;
    timer.Start();
}

CANSparkMaxGroup::CANSparkMaxGroup(const CANSparkMaxGroup& copy)
{
    for (uint32_t i = 0; i < copy.sparks.size(); i++)
        sparks.push_back(copy.sparks[i]);
    rampRate = copy.rampRate;
    timer.Start();
}

CANSparkMaxGroup::~CANSparkMaxGroup()
{

}

void CANSparkMaxGroup::AddCANSparkMax(rev::CANSparkMax* spark)
{
    sparks.push_back(spark);
}

void CANSparkMaxGroup::SetRampRate(double rampRate)
{
    this->rampRate = rampRate;
}

void CANSparkMaxGroup::Set(double speed)
{
    // Update the loop timer
    units::second_t loopTime = timer.Get();
    timer.Reset();

    // Cap the input speed
    speed = std::min(speed, 1.0);
    speed = std::max(speed, -1.0);

    // Determine the max change
    double maxChange = rampRate * loopTime.value();
    double currentSpeed = Get();

    // Calculate the new speed
    if (currentSpeed + maxChange < speed)
        speed = currentSpeed + maxChange;
    else if (currentSpeed - maxChange > speed)
        speed = currentSpeed - maxChange;

    // Set the new speed
    for (uint32_t i = 0; i < sparks.size(); i++)
        sparks[i]->Set(speed);
}

double CANSparkMaxGroup::Get()
{
    if (sparks.empty())
        return 0;

    double sum = 0;
    for (uint32_t i = 0; i < sparks.size(); i++)
        sum += sparks[i]->Get();
    return sum / sparks.size();
}

void CANSparkMaxGroup::Disable()
{
    for(uint32_t i = 0; i < sparks.size(); i++)
        sparks[i]->Disable();
}

void CANSparkMaxGroup::Stop()
{
    for(uint32_t i = 0; i < sparks.size(); i++)
        sparks[i]->StopMotor();
}

double CANSparkMaxGroup::GetPosition()
{
    if (sparks.empty())
        return 0;

    double sum = 0;
    for (uint32_t i = 0; i < sparks.size(); i++)
        sum += sparks[i]->GetEncoder().GetPosition();
    return sum / sparks.size();
}

double CANSparkMaxGroup::GetVelocity()
{
    if (sparks.empty())
        return 0;

    double sum = 0;
    for (uint32_t i = 0; i < sparks.size(); i++)
        sum += sparks[i]->GetEncoder().GetVelocity();
    return sum / sparks.size();
}

void CANSparkMaxGroup::SetPosition(double position)
{
    for (uint32_t i = 0; i < sparks.size(); i++)
        sparks[i]->GetEncoder().SetPosition(position);
}

void CANSparkMaxGroup::SetIdleMode(rev::CANSparkMax::IdleMode idleMode)
{
    for (uint32_t i = 0; i < sparks.size(); i++)
        sparks[i]->SetIdleMode(idleMode);
}

rev::CANSparkMax::IdleMode CANSparkMaxGroup::GetIdleMode()
{
    if (sparks.empty())
        return rev::CANSparkMax::IdleMode::kBrake;
    return sparks.front()->GetIdleMode();
}

CANSparkMaxGroup& CANSparkMaxGroup::operator=(const CANSparkMaxGroup& rhs)
{
    sparks.clear();
    for (uint32_t i = 0; i < rhs.sparks.size(); i++)
        sparks.push_back(rhs.sparks[i]);
    rampRate = rhs.rampRate;
    timer = rhs.timer;

    return *this;
}