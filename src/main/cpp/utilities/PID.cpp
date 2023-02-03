// Included headers
#include "utilities/PID.h"

PID::PID()
{
    kp = 1.0;
    ki = 1.0;
    kd = 1.0;
    ks = __DBL_MAX__;
    timer.Start();
    integral = 0.0;
    pastError = 0.0;
    target = 0.0;
}

PID::PID(double kp, double ki, double kd, double ks)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->ks = ks;
    timer.Start();
    integral = 0.0;
    pastError = 0.0;
    target = 0.0;
}

PID::PID(const PID& copy)
{
    kp = copy.kp;
    ki = copy.ki;
    kd = copy.kd;
    ks = copy.ks;
    timer = copy.timer;
    integral = copy.integral;
    pastError = copy.pastError;
    target = copy.target;
}

PID::~PID()
{

}

double PID::getProportional(double error)
{
    return error * kp;
}

double PID::getIntegral(double error, double loopTime)
{
    // Add the accumulated error from this loop
    integral += (error * loopTime);

    // Cap the integral at the saturation point
    if (ki != 0.0 && ks > 0.0)
        if (std::abs(integral) > std::abs(ks / ki))
            integral *= std::abs(ks / ki) / std::abs(integral);

    return ki * integral;
}

double PID::getDerivative(double error, double loopTime)
{
    double errorChange = error - pastError;
    pastError = error;
    return errorChange / loopTime * kd;
}

void PID::setTarget(double target)
{
    this->target = target;
}

double PID::getValue(double current)
{
    // Get the time since the last control loop
    double loopTime = timer.Get().value();
    timer.Reset();

    // Get the current error
    double error = target - current;

    // Get the 3 control values
    double pValue = getProportional(error);
    double iValue = getIntegral(error, loopTime);
    double dValue = getDerivative(error, loopTime);

    // Return the control value
    return pValue + iValue + dValue;
}

PID& PID::operator=(const PID& rhs)
{
    kp = rhs.kp;
    ki = rhs.ki;
    kd = rhs.kd;
    ks = rhs.ks;
    timer = rhs.timer;
    integral = rhs.integral;
    pastError = rhs.pastError;
    target = rhs.target;

    return *this;
}