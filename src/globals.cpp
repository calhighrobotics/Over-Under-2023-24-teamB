#include "main.h"

int subsystem = 1;
int auton = 1;
bool wings = false;

pros::Controller controller (pros::E_CONTROLLER_MASTER);
pros::Motor RightFront (6, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor LeftFront (-5, pros:: E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor LeftBack (-7, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor RightBack (8, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor LeftMid (-2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Puncher (19, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor RightMid (3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake (9, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Imu inertial_sensor(15);
pros::ADIDigitalOut wing ('A');
pros::ADIDigitalOut wing2 ('D');
pros::ADIDigitalOut pto_1 ('B');
pros::ADIDigitalOut pto_2 ('C');


pros::Motor_Group drive_left ({LeftFront, LeftMid, LeftBack});
pros::Motor_Group drive_right ({RightFront, RightMid, RightBack});
pros::Motor_Group drive_ ({LeftFront, RightFront, LeftMid, RightMid, LeftBack, RightBack});

lemlib::Drivetrain_t drivetrain {
    &drive_left, // left drivetrain motors
    &drive_right, // right drivetrain motors
    11.75, // track width
    3.25, // wheel diameter - 3.25 on competition bot, 4 on test drivetrain
	360 // wheel rpm - 360 rpm for competition bot, 200 for test drivetrain
};

lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial_sensor // inertial sensor
};


// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);