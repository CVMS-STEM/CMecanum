#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor lMotorA = motor(PORT1, ratio18_1, true);
motor lMotorB = motor(PORT11, ratio18_1, false);
motor_group l = motor_group(lMotorA, lMotorB);
motor rMotorA = motor(PORT10, ratio18_1, false);
motor rMotorB = motor(PORT20, ratio18_1, true);
motor_group r = motor_group(rMotorA, rMotorB);
controller Controller1 = controller(primary);
motor ClawMotorA = motor(PORT2, ratio18_1, true);
motor ClawMotorB = motor(PORT9, ratio18_1, false);
motor_group Claw = motor_group(ClawMotorA, ClawMotorB);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
