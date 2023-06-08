#include <Servo.h>

Servo ESC;
Servo Steering;

//define pinouts

#define pin_rcSteering 1
#define pin_rcThrottle 2
#define pin_rcLockout 3
#define pin_rcHorn 4
#define pin_rcSpeedLimit 5
#define pin_rcABS 6
#define pin_pedThrottle 7
#define pin_pedBrake 8
#define pin_outESC 9
#define pin_outSteering 10
#define pin_switchDirection 11
#define pin_switchSpeed 12

//set variables
int rcSteering;
int steeringOutput;
int rcThrottleInput;
int rcLockOut;
int throttleOutput;
int pedThrottleInput;
int pedBrakeInput;
int switchSpeed;
int switchDirection;
//int speedLimit;

//rc reciever
void readRC(){
    rcSteering = pulseIn(pin_rcSteering, HIGH, 200);
    rcThrottleInput = pulseIn(pin_rcThrottle, HIGH, 200);
    rcLockOut = pulseIn(pin_rcLockout, HIGH, 200);
    rcSteering = map(rcSteering,1000,2000,0,180);
    rcThrottleInput = map(rcThrottleInput,1000,2000,0,180);
    if (rcLockOut < 1500){
        rcLockOut = 1;
    } else {
        rcLockOut =0;
    }
    
}

//dashboard switches
void readSwitches(){
    switchDirection = digitalRead(pin_switchDirection);
    switchSpeed = digitalRead(pin_switchSpeed);
}

//hall effect pedals
void readPedals(){
    if (rcLockOut = 0){
        pedThrottleInput = analogRead(pin_pedThrottle);
        pedBrakeInput = analogRead(pin_pedBrake);
        pedThrottleInput = map(pedThrottleInput,0,1023,90,180);
        pedBrakeInput = map(pedBrakeInput,0,1023,90,0);
    } else {
        pedThrottleInput = 0;
        pedBrakeInput = 0;
    }
}

//determine appropriate throttle level
void setThrottle(){
    if (rcLockOut = 0){
        throttleOutput = max(rcThrottleInput,pedThrottleInput); //set throttle output to greater of pedal and rc
    } else {
        throttleOutput = rcThrottleInput;
    }
    if (switchSpeed = LOW){
        throttleOutput = map(throttleOutput,90,180,90,135); //cut throttle output to half if low speed switch is on
    }
    if (switchDirection = LOW){
        throttleOutput = map(throttleOutput,90,180,90,0); //set throttle output to range 90(stop) to 0 (full reverse)
    }
}

//go go go
void writeDrive(){
    Steering.write(steeringOutput);
    ESC.write(throttleOutput);
}

void setup() {
    ESC.attach(pin_outESC,1000,2000); //attach to dual motor esc
    Steering.attach(pin_outSteering,1000,2000); //attach to steering servo
}

void loop() {
    readRC;
    readPedals;
    readSwitches;
    setThrottle;
    writeDrive;
}