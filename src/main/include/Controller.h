// Inclusion guard
#ifndef CONTROLLER_H
#define CONTROLLER_H

// Included libraries
#include <frc/XboxController.h>

/**
 * This class manages the controller input
 * @author FRC 171 - Cheese Curd Herd
 */
class Controller
{
private:
    /**
     * The controller being managed by the class
     */
    frc::XboxController controller{0};

    /**
     * The home positions for the joysticks
     */
    double homeLeftX;
    double homeLeftY;
    double homeRightX;
    double homeRightY;

public:
    Controller();
    void initialize();
    bool getAButton();
    bool getAButtonPressed();
    bool getAButtonReleased();
    int getAxisCount();
    int getAxisType(int axis);
    bool getBackButton();
    bool getBackButtonPressed();
    bool getBackButtonReleased();
    bool getBButton();
    bool getBButtonPressed();
    bool getBButtonReleased();
    int getButtonCount();
    bool getLeftBumper();
    bool getLeftBumperPressed();
    bool getLeftBumperReleased();
    bool getLeftStickButton();
    bool getLeftStickButtonPressed();
    bool getLeftStickButtonReleased();
    double getLeftTriggerAxis();
    double getLeftX();
    double getLeftY();
    std::string getName();
    int getPort();
    int getPOV(int pov = 0);
    int getPOVCount();
    double getRawAxis(int axis);
    bool getRawButton(int button);
    bool getRawButtonPressed(int button);
    bool getRawButtonReleased(int button);
    bool getRightBumper();
    bool getRightBumperPressed();
    bool getRightBumperReleased();
    bool getRightStickButton();
    bool getRightStickButtonPressed();
    bool getRightStickButtonReleased();
    double getRightTriggerAxis();
    double getRightX();
    double getRightY();
    bool getStartButton();
    bool getStartButtonPressed();
    bool getStartButtonReleased();
    frc::GenericHID::HIDType getType();
    bool getXButton();
    bool getXButtonPressed();
    bool getXButtonReleased();
    bool getYButton();
    bool getYButtonPressed();
    bool getYButtonReleased();
    bool isConnected();
    void setOutput(int outputNumber, bool value);
    void setOutputs(int value);
    void setRumble(frc::GenericHID::RumbleType type, double value);
};

#endif