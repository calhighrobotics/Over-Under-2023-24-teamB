#pragma once
#include "api.h"
#include "lemlib/api.hpp"

// The following files are imported in order to provide type definitions into the compiler that allows for the objecys to
#include "robot/wings.h"



/**
 * @file globals.h
 * @brief Contains global variables and type definitions for the Robot namespace.
 */

/**
 * @namespace Robot
 * @details In order to construct the robot, the Robot namespace is used to contain all of the objects that are used to control the robot. This includes the subsystems, methods, and global objects.
 * We use PROS extensively for the robot, it can be found at <A HREF="https://pros.cs.purdue.edu">PROS</A>
 * @authors Absozero, Jaytb
     * @brief Contains all objects generated by the 1516B team - Contains all of the subsystems, methods, and global objects.
     */
namespace Robot {

    /**
     * @brief Contains global variables and type definitions for the Robot namespace.
     * @details The majority of the global variables are defined in the Globals namespace. This is to allow for easy access to the variables from any file in the project. 
     * The Globals namespace is also used to hold lemlib objects that are used to control the autonomous functions of the robot. It contains parameters that are used to control
     * the PID that lemlib uses, additionally.
     */
    namespace Globals {
        extern pros::Controller controller;

        extern Robot::Wings robotWings;

        extern pros::Motor RightFront;
        extern pros::Motor LeftFront;
        extern pros::Motor LeftBack;
        extern pros::Motor RightBack;
        extern pros::Motor LeftMid;
        extern pros::Motor PuncherMotor;
        extern pros::Motor PuncherMotor2;
        extern pros::Motor RightMid;
        extern pros::Motor IntakeMotor;

        extern pros::Imu inertial_sensor;
        extern pros::Distance distance;


        extern pros::ADIDigitalOut FrontWing;
        extern pros::ADIDigitalOut BackWing1;
        extern pros::ADIDigitalOut BackWing2;
        extern pros::ADIDigitalOut Elevator;

        extern pros::Motor_Group punchers;
        extern pros::Motor_Group drive_left;
        extern pros::Motor_Group drive_right;
        // Used as a motor group meant to be passed into lemlib, a full drivetrain group.
	extern pros::Motor_Group drive_;

        extern lemlib::Drivetrain_t drivetrain;

        extern lemlib::OdomSensors_t sensors;


        // forward/backward PID
        extern lemlib::ChassisController_t lateralController;
        
        // turning PID
        extern lemlib::ChassisController_t angularController;

        extern lemlib::Chassis chassis;

        extern pros::ADIDigitalIn puncherToggleSwitch;
        extern pros::ADIDigitalIn autonToggleSwitch;
        extern pros::ADIDigitalIn drivetrainToggleSwitch;
    }
} // namespace Robot
