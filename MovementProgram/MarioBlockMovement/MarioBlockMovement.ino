//Function Prototypes.
void printPushButtonsValues();
void readPushButtons();
void readShroomSensors();

void handlePushButtonState();
void handleCoinState();
void handleFlowerState();
void handleShroomState();

//OUTPUT PIN ASSIGNMENTS
const int SHROOM_HOR_DIR_PIN = A5;
const int COIN_MOTOR_POWER_PIN = 13;
const int FLOWER_MOTOR_POWER_PIN = 11;
const int SHROOM_HOR_POWER_PIN = A2;
const int SHROOM_VER_POWER_PIN = 2;

//INPUT PIN ASSIGNMENTS
const int SHROOM_SENSOR_LEFT_PIN = 5;
const int SHROOM_SENSOR_RIGHT_PIN = 6 ; 
const int COIN_PUSH_PIN = 12;//7;
const int FLOWER_PUSH_PIN = 8;
const int SHROOM_PUSH_PIN = 9;

const unsigned long COIN_INTERVAL = 6000;
const unsigned long FLOWER_INTERVAL = 6000;
const unsigned long SHROOM_INTERVAL = 6000;

const bool LEFT = 0;
const bool RIGHT = 255;
bool shroomMoving = false;

//Typedefs
typedef enum{
  STATE_COIN_UP,
  STATE_COIN_DOWN,
  STATE_COIN_NUM,
} COIN_STATE;

typedef enum{
  STATE_FLOWER_UP,
  STATE_FLOWER_DOWN,
  STATE_FLOWER_NUM,
} FLOWER_STATE;

typedef enum{
  STATE_SHROOM_UP,
  STATE_SHROOM_DOWN,
  STATE_VER_SHROOM_NUM,
} SHROOM_VER_STATE;

typedef enum{
  STATE_SHROOM_LEFT,
  STATE_SHROOM_RIGHT,
  STATE_HOR_SHROOM_NUM,
} SHROOM_HOR_STATE;

//Global Variables
int pushButtonPins[] = {COIN_PUSH_PIN,FLOWER_PUSH_PIN, SHROOM_PUSH_PIN};
int shroomSensorPins[] = {SHROOM_SENSOR_LEFT_PIN, SHROOM_SENSOR_RIGHT_PIN};

int pushButtonValues[3] = {LOW,LOW,LOW};
COIN_STATE machineCoinState;
FLOWER_STATE machineFlowerState;
SHROOM_HOR_STATE machineShroomHorState;
SHROOM_VER_STATE machineShroomVerState;

unsigned long coinPreviousMillis = 0;
unsigned long flowerPreviousMillis = 0;
unsigned long shroomPreviousMillis = 0;

void setup() {
  Serial.begin(9600);
  //OUTPUT PIN ASSIGNMENTS
  pinMode(COIN_MOTOR_POWER_PIN, OUTPUT);
  pinMode(FLOWER_MOTOR_POWER_PIN, OUTPUT);
  pinMode(SHROOM_HOR_POWER_PIN, OUTPUT);
  pinMode(SHROOM_VER_POWER_PIN, OUTPUT);
  pinMode(SHROOM_HOR_DIR_PIN, OUTPUT);

  //INPUT PIN ASSIGNMENTS
  //Push buttons
  pinMode(COIN_PUSH_PIN, INPUT_PULLUP);
  pinMode(FLOWER_PUSH_PIN, INPUT_PULLUP);
  pinMode(SHROOM_PUSH_PIN, INPUT_PULLUP);

  //Shroom stuff
  pinMode(SHROOM_SENSOR_LEFT_PIN, INPUT_PULLUP);
  pinMode(SHROOM_SENSOR_RIGHT_PIN, INPUT_PULLUP);

  machineCoinState == STATE_COIN_DOWN;
  machineShroomVerState == STATE_SHROOM_DOWN;
  machineShroomHorState == STATE_SHROOM_LEFT;

  digitalWrite(COIN_MOTOR_POWER_PIN, HIGH); //Stop coin motor.
  digitalWrite(SHROOM_VER_POWER_PIN, HIGH); //Stop coin motor.
  analogWrite(SHROOM_HOR_POWER_PIN, HIGH); //Stop coin motor.
  digitalWrite(FLOWER_MOTOR_POWER_PIN, HIGH); //Stop coin motor.
}

void loop() {
  unsigned long coinCurrentMill = millis();
  unsigned long flowerCurrentMill = millis();
  unsigned long shroomCurrentMill = millis();

//  if ( digitalRead(COIN_PUSH_PIN)){
//    Serial.println("coin button pushed");
//  }else{
//    Serial.println("coin button not pushed");
//  }

  if(digitalRead(COIN_PUSH_PIN) && machineCoinState == STATE_COIN_DOWN){
    // Move the coin up only when the coin is down.
    //Serial.println("Coin button pushed move coin up");
    machineCoinState = STATE_COIN_UP;
    coinPreviousMillis = millis();
    digitalWrite(COIN_MOTOR_POWER_PIN, LOW);
  }

  if(machineCoinState == STATE_COIN_UP){
    // Coin is already up, need to check when to put it down.
    //Serial.println("Coin is held up. check if need to put down");
    if( millis() - coinPreviousMillis > COIN_INTERVAL) {
      //Times Up, put the coint down
      machineCoinState = STATE_COIN_DOWN;
      digitalWrite(COIN_MOTOR_POWER_PIN, HIGH);
     // Serial.println("Times up put coin down. >>>>>>>>>>>>>>>");
    }
  }
   
//CODE BELOW IS FOR FLOWER STUFF
  if ( digitalRead(FLOWER_PUSH_PIN)){
    //Serial.println("flower button pushed");
  }else{
    //Serial.println("flower button not pushed");
  }

  if(digitalRead(FLOWER_PUSH_PIN) && machineFlowerState == STATE_FLOWER_DOWN){
    // Move the flower up only when the flower is down.
    //Serial.println("flower button pushed move flower up");
    machineFlowerState = STATE_FLOWER_UP;
    flowerPreviousMillis = millis();
    digitalWrite(FLOWER_MOTOR_POWER_PIN, LOW);
  }

  if(machineFlowerState == STATE_FLOWER_UP){
    // flower is already up, need to check when to put it down.
    //Serial.println("flower is held up. check if need to put down");
    if( millis() - flowerPreviousMillis > FLOWER_INTERVAL) {
      //Times Up, put the flowert down
      machineFlowerState = STATE_FLOWER_DOWN;
      digitalWrite(FLOWER_MOTOR_POWER_PIN, HIGH);
      //Serial.println("Times up put flower down. >>>>>>>>>>>>>>>");
    }
   }

//CODE BELOW IS FOR SHROOM STUFF
  if ( digitalRead(SHROOM_PUSH_PIN)){
    Serial.println("shroom button pushed");
  }else{
    Serial.println("shroom button not pushed");
  }
    machineShroomVerState== STATE_SHROOM_DOWN;
if ( machineShroomVerState == STATE_SHROOM_DOWN ){
    Serial.println("state Down");
  }else{
    Serial.println("state UP");
  }

  if ( machineShroomHorState == STATE_SHROOM_LEFT ){
    Serial.println("state left");
  }else{
    Serial.println("state right");
  }


  if(digitalRead(SHROOM_PUSH_PIN) && shroomMoving == false){
    // Move the shroom up only when the shroom is down and right.
    Serial.println("shroom button pushed move shroom up");
    shroomMoving = true;
    digitalWrite(SHROOM_VER_POWER_PIN, LOW); // Move shroom up
    machineShroomVerState = STATE_SHROOM_UP;
    delay(3000);
    analogWrite(SHROOM_HOR_POWER_PIN, 255);
    digitalWrite(SHROOM_HOR_DIR_PIN, RIGHT);
    delay(500);
  }

  if(machineShroomVerState == STATE_SHROOM_UP ){
    // shroom is already up, need to check when to put it down.
   // Serial.println("shroom is held up. check if need to put down");
    if( digitalRead(SHROOM_SENSOR_RIGHT_PIN) == LOW) {
      digitalWrite(SHROOM_VER_POWER_PIN, HIGH); // Move the shroom down
      machineShroomVerState = STATE_SHROOM_DOWN;
      Serial.println("Reached the right side, put the shroom down. >>>>>>>>>>>>>>>");
      digitalWrite(SHROOM_HOR_DIR_PIN,LEFT);  // Move to other side.
      analogWrite(SHROOM_HOR_POWER_PIN, 0); //Turn off chain
      delay(1500); //Wait for shroom to drop
      analogWrite(SHROOM_HOR_POWER_PIN, 255); //Turn on chain
  }else{
      //Serial.println("Shroom not up yet<<<<<");
    }    
  }
 
  if( digitalRead(SHROOM_SENSOR_LEFT_PIN) == LOW){
    digitalWrite(SHROOM_VER_POWER_PIN, HIGH);
    analogWrite(SHROOM_HOR_POWER_PIN, 0);
    shroomMoving = false;
  } 

//  if( machineShroomVerState == STATE_SHROOM_DOWN && machineShroomHorState == STATE_SHROOM_RIGHT){
//    //Serial.println(" Shroom is on the right , bing it to left.");
//    machineShroomHorState = STATE_SHROOM_RIGHT; // Already on the right
//
//    //machineShroomHorState = STATE_SHROOM_LEFT;
//    shroomPreviousMillis = millis();
//    analogWrite(SHROOM_HOR_POWER_PIN, LEFT);
//    delay(10); 
//  }
//
//  if( machineShroomVerState == STATE_SHROOM_RIGHT){
//    //Serial.println(" Shroom is on the right , bing it to left.");
//    machineShroomHorState = STATE_SHROOM_LEFT;
//    shroomPreviousMillis = millis();
//    analogWrite(SHROOM_HOR_POWER_PIN, LOW);
//  }

} //end of loop

//void printPushButtonsValues(){
//  for(int pin =0; pin<3 ;pin++){
//    Serial.print("pin");
//    Serial.print(pin);
//    Serial.print("is");
//    Serial.print(pushButtonValues[pin]);
//    Serial.println();  
//  }
//}

//void handlePushButtonState(){
//  if (pushButtonValues[0] > 512 ){ 
//    Serial.println("Coin button pushed");
//    machineCoinState = STATE_COIN_UP;
//  }
//  if (pushButtonValues[1]){
//    Serial.println("Flower button pushed");
//    machineFlowerState = STATE_FLOWER_UP;
//  }
//  if (pushButtonValues[2]){
//    Serial.println("Shroom button pushed");
//    machineShroomVerState = STATE_SHROOM_UP;
//  }
//  delay(1000);
//}
//
//
//void readShroomSensors(){
//  digitalRead(SHROOM_PUSH_PIN);
//};
//

