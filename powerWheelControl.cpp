#include <ServoInput.h>

//define pinouts

#define pin_rcSteering
#define pin_rcThrottle
#define pin_rcLockout
#define pin_rcHorn
#define pin_rcSpeedLimit
#define pin_rcABS
#define pin_pedThrottle
#define pin_pedBrake
#define pin_outESC
#define pin_outSteering

//set variables
int rcSteering;
int steeringDirection;
int rcThrottleInput;
int pedThrottleInput;
int speedLimit;
int throttleOutput;

void setup() {
}

void readRC(){

}

void readPedals(){

}

void setThrottle(){

}

void writeESC(){

}

void loop() {

readRC;
readPedals;
setThrottle;
writeESC;


}