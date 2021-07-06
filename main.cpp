/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\duwil.JULIA                                      */
/*    Created:      Sun Jun 27 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// l                    motor_group   1, 11           
// r                    motor_group   10, 20          
// Controller1          controller                    
// Claw                 motor_group   2, 9            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
const double tConst = 57.2957795130823; // 180/ pi 
const directionType bk = reverse;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  
  vexcodeInit();
  r.setVelocity(30, percent);
  l.setVelocity(30, percent);
  while (true){
    double joy3 = Controller1.Axis3.position();
    double joy4 = Controller1.Axis3.position();
    bool BU = Controller1.ButtonUp.pressing();
    bool BD = Controller1.ButtonDown.pressing();
    bool BL = Controller1.ButtonLeft.pressing();
    bool BR = Controller1.ButtonRight.pressing();
    if (joy3 != 0 and joy4 != 0){
      double diagVel = 0; 
      if (joy3 * joy4 > 0){
        diagVel = (joy3+ joy4);
        r.setVelocity(diagVel, percentUnits::pct);
        r.spin(directionType::fwd);
      } else {
        diagVel = 0.25*(joy3- joy4);// 
        l.setVelocity(diagVel, percentUnits::pct);
        l.spin(directionType::fwd);
      }
    } else if (BU){
      r.setVelocity(50, percentUnits::pct);
      l.setVelocity(50, percentUnits::pct); 
      l.spin(directionType::fwd);
      r.spin(directionType::fwd);
    } else if (BD){
      r.spin(directionType::rev, 30, percentUnits::pct);
      l.spin(directionType::rev, 30, percentUnits::pct);
    } else if (BL){ 
      r.spin(directionType::rev, 30, percentUnits::pct);
      l.spin(directionType::fwd, 30, percentUnits::pct);
    } else if (BR){
      r.spin(directionType::fwd, 30, percentUnits::pct);
      l.spin(directionType::rev, 30, percentUnits::pct);
    } else{
      r.stop(brakeType::hold);
      l.stop(brakeType::hold);
    }
    wait(100, timeUnits::msec); // 
  }
}
void f(bool direc, double length){ // can be used for autonomous
  double disR = ((length )*tConst )/ 4; //distance rotated
  r.setStopping(brakeType::hold);
  l.setStopping(brakeType::hold);
  if (disR > 0){
    r.spinFor(directionType::fwd, disR, rotationUnits::deg);
    l.spinFor(directionType::fwd, disR, rotationUnits::deg);
  } else{
    r.spinFor(bk, disR, rotationUnits::deg);
    l.spinFor(bk, disR, rotationUnits::deg);
  }
}
void turn(bool lr, double deg){
  if (lr == true){
     
  }
}
/*MECANUM DRIVE 
LJoystick for diagonal movement
  (^)
(<) (>)
  (v)
  for n e s w
 */
