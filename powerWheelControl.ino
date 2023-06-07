//#include <ServoInput.h>

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

//set variables
int rcSteering;
int steeringOutput;
int rcThrottleInput;
int rcLockOut;
int throttleOutput;
int pedThrottleInput;
int pedBrakeInput;
//int speedLimit;

void readRC(){
    rcSteering = pulseIn(pin_rcSteering, HIGH, 200);
    rcThrottleInput = pulseIn(pin_rcThrottle, HIGH, 200);
    rcLockOut = pulseIn(pin_rcLockout, HIGH, 200);
    rcSteering = map(rcSteering,1000,2000,-30,30);
    rcThrottleInput = map(rcThrottleInput,1000,2000,-100,100);
    if (rcLockOut < 1500){
        rcLockOut = 1;
    } else {
        rcLockOut =0;
    }
    
}

void readPedals(){
    if (rcLockOut = 0){
        pedThrottleInput = analogRead(pin_pedThrottle);
        pedBrakeInput = analogRead(pin_pedBrake);
        pedThrottleInput = map(pedThrottleInput,0,1023,0,100);
        pedBrakeInput = map(pedBrakeInput,0,1023,0,100);
    } else {
        pedThrottleInput = 0;
        pedBrakeInput = 0;
    }
}

void setThrottle(){
    if (rcLockOut = 0){
        throttleOutput = max(rcThrottleInput,pedThrottleInput);
    } else {
        throttleOutput = rcThrottleInput;
    }
}
void writeESC(){
    analogWrite(pin_outESC,throttleOutput);
}

void writeSteering(){
    analogWrite(pin_outSteering,rcSteering);
}

void setup() {
}

void loop() {

readRC;
readPedals;
setThrottle;
writeESC;
writeSteering;


}