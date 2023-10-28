/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\debas                                            */
/*    Created:      Sun Jun 25 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftFront            motor         1               
// RightFront           motor         2               
// LeftBack             motor         3               
// RightBack            motor         4               
// Controller1          controller                    
// LeftMid              motor         5               
// RightMid             motor         6               
// Catapult             motor         7               
// Intake               motor         8                      
// ---- END VEXCODE CONFIGURED DEVICES ----



#include "vex.h"
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <fstream>
//#include <auton.cpp>


using namespace vex;

// A global instannce of competition
competition Competition;

/*
           ___
          |_|_|
          |_|_|              _____
          |_|_|     ____    |*_*_*|
 _______   _\__\___/ __ \____|_|_   _______
/ ____  |=|      \  <_+>  /      |=|  ____ \
~|    |\|=|======\\______//======|=|/|    |~
 |_   |    \      |      |      /    |    |
  \==-|     \     |1516B |     /     |----|~~/
  |   |      |    |      |    |      |____/~/
  |   |       \____\____/____/      /    / /
  |   |         {----------}       /____/ /
  |___|        /~~~~~~~~~~~~\     |_/~|_|/
   \_/        |/~~~~~||~~~~~\|     /__|\
   | |         |    ||||    |     (/|| \)
   | |        /     |  |     \       \\
   |_|        |     |  |     |
              |_____|  |_____|
              (_____)  (_____)
              |     |  |     |
              |     |  |     |
              |/~~~\|  |/~~~\|
              /|___|\  /|___|\
             <_______><_______>
*/


int check_next(int index, std::vector<uint8_t> values, int extent, int motorMax) {

  while (1) {
    bool pass = true;
    if (motorMax*2 < values.size()) {
      for (int i=0; i < motorMax; i++) {
        if (values[index+i] != values[index+motorMax]) {
          pass = false;
        }
      }
    }
    if (pass) {
      index += motorMax;
      extent += 1;
    } else {
      return extent;
    }
    

    /*if (index+23 < values.size() && values[index] == values[index+12] && values[index+1] == values[index+13] && values[index+2] == values[index+14] && values[index+3] == values[index+15] && values[index+4] == values[index+16] && values[index+5] == values[index+17] && values[index+6] == values[index+18] && values[index+7] == values[index+19] && values[index+8] == values[index+20]&& values[index+9] == values[index+21] && values[index+10] == values[index+22] && values[index+11] == values[index+23]) {
        index += 12;
        extent += 1;
    } else {
      return extent;
    }*/
  }
}


void pre_auton(void) {
  vexcodeInit();

  

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {
//auton();
//std::ifstream file("rerun.txt", std::ios::binary);
  std::cout << "\x1B[2J\x1B[H";
  printf("\033[33m Started autonomous routine.\n");
  uint8_t count[1];
  FILE* file = fopen("count.txt", "r");
  int c;
  if ((c = fgetc(file)) != EOF) {
    count[0] = static_cast<uint8_t>(c);
}
//Brain.SDcard.loadfile("count.txt", reinterpret_cast<uint8_t*>(count), 1);
int size = count[0];


uint8_t data[size];
//std::vector<uint8_t> data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//Brain.SDcard.loadfile("rerun.txt", reinterpret_cast<uint8_t*>(data), size);

file = fopen("rerun.txt", "r");
if (file == nullptr) {Brain.Screen.print("Error opening file");}
int i = 0;
while ((c = fgetc(file)) != EOF && i < size) {
  data[i] = static_cast<uint8_t>(c);
  i++;
}
fclose(file);

  Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("size: %d ", size);

for (int i=0; i < size; i+=8) {
  Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("iteration %d ", i);

  RightFront.spin(vex::directionType::rev, data[i], vex::velocityUnits::pct);
  RightBack.spin(vex::directionType::rev, data[i+1], vex::velocityUnits::pct);
  LeftFront.spin(vex::directionType::rev, data[i+2],  vex::velocityUnits::pct);
  LeftBack.spin(vex::directionType::rev, data[i+3], vex::velocityUnits::pct);
  LeftMid.spin(vex::directionType::rev, data[i+4], vex::velocityUnits::pct);
  RightMid.spin(vex::directionType::rev, data[i+5], vex::velocityUnits::pct);
  Catapult.spin(vex::directionType::fwd, data[i+6], vex::velocityUnits::pct);
  Intake.spin(vex::directionType::rev, data[i+7], vex::velocityUnits::pct);

if (i == 152) {
  Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("should end here");
}


  if (i == 160) {
Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("rf: %d ", data[i]);
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("rb: %d ", data[i+1]);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("lf: %d ", data[i+2]);
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("lb: %d ", data[i+3]);
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("lm: %d ", data[i+4]);
    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("rf: %d ", data[i+5]);
    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("ca: %d ", data[i+6]);
    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("in %d ", data[i+7]);

    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[0]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[1]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[2]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[3]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[4]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[5]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[6]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", data[7]);

  }
    
  /*
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Right Front Drivetrain Motor: %.2f% ", RightFront.velocity(vex::velocityUnits::pct));
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Left Front Drivetrain Motor: %.2f% ", LeftFront.velocity(vex::velocityUnits::pct));
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("Right back drivetrain Motor: %.2f% ", RightBack.velocity(vex::velocityUnits::pct));
    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("Left back drivetrain Motor: %.2f% ", LeftBack.velocity(vex::velocityUnits::pct));
    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("Intake left motor: %.2f% ", IntakeLeft.velocity(vex::velocityUnits::pct));
    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("Intake right motor: %.2f% ", IntakeRight.velocity(vex::velocityUnits::pct));
    Brain.Screen.setCursor(9, 1);
    Brain.Screen.print("Elevation motor: %.2f% ", Elevation.velocity(vex::velocityUnits::pct));
    Brain.Screen.setCursor(10, 1);
    Brain.Screen.print("Catapult motor: %.2f% ", Elevation.velocity(vex::velocityUnits::pct));
    */

  task::sleep(10);

  //task::sleep(check_next(i, data, 1, 4)*10);
  //i += 4*check_next(i, data, 1, 4) - 4;
}

//file.close();


  RightFront.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
  RightBack.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
  LeftFront.spin(vex::directionType::rev, 0,  vex::velocityUnits::pct);
  LeftBack.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
  LeftMid.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
  RightMid.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
  Catapult.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Intake.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);


}


void initRerun(int rf, int rb, int lf, int lb, int lm, int rm, int cat, int intake) {
      uint8_t arr[8];
      arr[0] = rf;
      arr[1] = rb;
      arr[2] = lf;
      arr[3] = lb;
      arr[4] = lm;
      arr[5] = rm;
      arr[6] = cat;
      arr[7] = intake;

      uint8_t count[1];
      count[0] = 0;
      std::cout << "\x1B[2J\x1B[H";
      printf("\033[33m Rerun called, array written.\n");
      Brain.SDcard.savefile("rerun.txt", arr, sizeof(arr));
      Brain.SDcard.savefile("count.txt", count, sizeof(count));
}

void saveFrame(int rf, int rb, int lf, int lb, int lm, int rm, int cat,int intake, int pr) {
      //brain.SDcard.savefile(const char *name, uint8_t *buffer, uint32_t len);
      //"RFront.spin(vex::directionType::rev, rf, vex::velocityUnits::pct);"
      uint8_t arr[8];
      arr[0] = rf;
      std::cout << "\033[32m Right front: " << arr[0];
      arr[1] = rb;
      std::cout << "\033[32m Right back: " << arr[1];
      arr[2] = lf;
      std::cout << "\033[32m Left front: " << arr[2];
      arr[3] = lb;
      std::cout << "\033[32m Left back: " << arr[3];
      arr[4] = lm;
      std::cout << "\033[32m Left Middle: " << arr[4];
      arr[5] = rm;
      std::cout << "\033[32m Right Middle: " << arr[5];
      arr[6] = cat;
      std::cout << "\033[32m Catapult: " << arr[6];
      arr[7] = intake;
      std::cout << "\033[32m Intake: " << arr[7];
      uint8_t count[1];
    /*if (pr == 50) {
          Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("rf: %d ", arr[0]);
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("rb: %d ", arr[1]);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("lf: %d ", arr[2]);
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("lb: %d ", arr[3]);
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("lm: %d ", arr[4]);
    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("rf: %d ", arr[5]);
    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("ca: %d ", arr[6]);
    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("in %d ", arr[7]);


    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[0]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[1]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[2]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[3]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[4]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[5]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[6]);
    std::cout << "\x1B[2J\x1B[H";
    printf("\033rf: %d ", arr[7]);
    }*/



      FILE* file = fopen("count.txt", "r");
      if (file == nullptr) {
        Brain.Screen.print("Error opening file");
      }
      int c;
      if ((c = fgetc(file)) != EOF) {
        count[0] = static_cast<uint8_t>(c);
      }
      fclose(file);
      //Brain.SDcard.loadfile("count.txt", reinterpret_cast<uint8_t*>(count), 1);
      count[0] += 8;
      Brain.Screen.clearScreen();
      Brain.Screen.print("c: %d ", count[0]);
      printf("\033[32m Rerun function is running\n");
      Brain.SDcard.appendfile("rerun.txt", arr, sizeof(arr));
      Brain.SDcard.savefile("count.txt", count, sizeof(count));
      
      

}

void endRerun(void) {
    uint8_t count[1];
    FILE* file = fopen("count.txt", "r");
    if (file == nullptr) {Brain.Screen.print("Error opening file");}
    int c;
    if ((c = fgetc(file)) != EOF) {
      count[0] = static_cast<uint8_t>(c);
    }
    //Brain.SDcard.loadfile("count.txt", reinterpret_cast<uint8_t*>(count), 1);
    uint8_t data[count[0]];
    int written = Brain.SDcard.loadfile("rerun.txt", data, sizeof(data));
    Brain.Screen.clearScreen();
      if (written > 0) {
        std::cout << "\x1B[2J\x1B[H";
        printf("\033[32m Wrote bytes to the SD card.\n");
        Brain.Screen.setCursor( 2, 2 );
        Brain.Screen.print("We wrote %d bytes to the SD Card", written );
      } else {
        std::cout << "\x1B[2J\x1B[H";
        printf("\033[32m Write failed.\n");
        Brain.Screen.setCursor( 2, 2 );
        Brain.Screen.print( "Write failed!");
      }
}

void usercontrol(void) {
  bool rerun = false;
  digital_out dig1 = digital_out(Brain.ThreeWirePort.B);
  digital_out dig2 = digital_out(Brain.ThreeWirePort.A);

  int pr = 0;
  while (1) {

    //Drivetrain
    RightFront.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value(), vex::velocityUnits::pct);
    RightBack.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value(), vex::velocityUnits::pct);
    RightMid.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value(), vex::velocityUnits::pct);
    LeftFront.spin(vex::directionType::rev, Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value(),  vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::rev, Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value(), vex::velocityUnits::pct);
    LeftMid.spin(vex::directionType::rev, Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value(), vex::velocityUnits::pct);


    int cat;
    //Catapult
    if (Controller1.ButtonA.pressing()) {
      std::cout << "\x1B[2J\x1B[H";
      Catapult.spin(vex::directionType::fwd, 140, vex::velocityUnits::pct);
      cat = 140;
      printf("\033[33m Button A pressed\n");
    } else if (Controller1.ButtonY.pressing()) {
      Catapult.spin(vex::directionType::fwd, -140, vex::velocityUnits::pct);
      cat = -140;
      std::cout << "\x1B[2J\x1B[H";
      printf("\033[33m Button Y pressed\n"); 
    } else {
      Catapult.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
      cat = 0;
    }

    //Elevation
    // if (Controller1.ButtonX.pressing()) {
    //   std::cout << "\x1B[2J\x1B[H";
    //   printf("\033[33m Button X pressed\n");
    //   Elevation.spin(vex::directionType::fwd, 140, vex::velocityUnits::pct);
    // } else {
    //   Elevation.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    // }

    //pneumatics
    if (Controller1.ButtonL1.pressing()) {
      printf("\033[35m Button L1 pressed\n");
      dig1.set(true);
      dig2.set(true);
    } else if (Controller1.ButtonL2.pressing()) {
      printf("\033[34m Button L2 pressed\n");
      dig1.set(false);
      dig2.set(false);
    }

    //Intake
    int intake;
    if (Controller1.ButtonR1.pressing()) {
      printf("\033[32m Button R1 pressed\n");
      Intake.spin(vex::directionType::rev, 140, vex::velocityUnits::pct);
      intake = 140;
    } else if (Controller1.ButtonR2.pressing()) {
      printf("\033[31m Button R2 pressed\n");
      Intake.spin(vex::directionType::rev, -140, vex::velocityUnits::pct);
      intake = -140;
    } else {
      intake = 0;
      Intake.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
    }


    int rf = Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value();
    int rb = Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value();
    int rm = Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value();
    int lf = Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value();
    int lb = Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value();
    int lm = Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value();



    //Rerun 
    if (Brain.SDcard.isInserted()) {
    if (Controller1.ButtonUp.pressing()) {
      std::cout << "\x1B[2J\x1B[H";
      printf("\033[37m rerun is activated\n");
      rerun = true;
      initRerun(rf, rb, lf, lb, lm, rm, cat, intake);
    } 
    if (rerun) {
      
      
      saveFrame(rf, rb, lf, lb, lm, rm, cat, intake, pr);
      pr++;
      std::cout << "\x1B[2J\x1B[H";
      printf("\033[37m Capturing rerun data\n");
    }
    if (Controller1.ButtonDown.pressing()) {
      rerun = false;
      printf("\033[37m rerun is stopped\r");
      //endRerun();
    }
  }
/*
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Right Front Drivetrain Motor: %.2f% ", RightFront.temperature(fahrenheit));
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Left Front Drivetrain Motor: %.2f% ", LeftFront.temperature(fahrenheit));
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("Right middle Drivetrain Motor: %.2f% ", RightMid.temperature(fahrenheit));
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("Left middle Drivetrain Motor: %.2f% ", LeftMid.temperature(fahrenheit));
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("Right back drivetrain Motor: %.2f% ", RightBack.temperature(fahrenheit));
    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("Left back drivetrain Motor: %.2f% ", LeftBack.temperature(fahrenheit));
    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("Intake left motor: %.2f% ", IntakeLeft.temperature(fahrenheit));
    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("Intake right motor: %.2f% ", IntakeRight.temperature(fahrenheit));
    Brain.Screen.setCursor(9, 1);
    Brain.Screen.print("Elevation motor: %.2f% ", Elevation.temperature(fahrenheit));
    Brain.Screen.setCursor(10, 1);
    Brain.Screen.print("Catapult motor: %.2f% ", Elevation.temperature(fahrenheit));
    */
}
}

/*
void autonomous(void) {
    RightFront.spin(vex::directionType::rev, -100, vex::velocityUnits::pct);
    RightBack.spin(vex::directionType::rev, -100, vex::velocityUnits::pct);
    LeftFront.spin(vex::directionType::rev, -100,  vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::rev, -100, vex::velocityUnits::pct);
    task::sleep(500);

    RightFront.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    RightBack.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    LeftFront.spin(vex::directionType::rev, 0,  vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);

    for (int i=0; i < 50; i++) {
      Catapult.spin(vex::directionType::fwd, 140, vex::velocityUnits::pct);

      task::sleep(100);

      Catapult.spin(vex::directionType::fwd, -140, vex::velocityUnits::pct);

      task::sleep(900);
    }
}*/

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
  
}