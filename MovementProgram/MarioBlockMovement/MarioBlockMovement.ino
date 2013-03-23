//Function Prototypes.
void printPushButtonsValues();
void readPushButtons();
void readShroomSensors();

void handlePushButtonState();
void handleCoinState();
void handleFlowerState();
void handleShroomState();
 
//OUTPUT PIN ASSIGNMENTS
const int SHROOM_HOR_DIR_PIN = 0;
const int COIN_MOTOR_POWER_PIN = 1;
const int FLOWER_MOTOR_POWER_PIN = 2;
const int SHROOM_HOR_POWER_PIN = 3;
const int SHROOM_VER_POWER_PIN = 4;

//INPUT PIN ASSIGNMENTS
const int SHROOM_SENSOR_LEFT_PIN = 5;
const int SHROOM_SENSOR_RIGTH_PIN = 6 ; 
const int COIN_PUSH_PIN = 7;
const int FLOWER_PUSH_PIN = 8;
const int SHROOM_PUSH_PIN = 9;

const unsigned long COIN_INTERVAL = 3000;
const unsigned long FLOWER_INTERVAL = 3000;

const bool LEFT = HIGH;
const bool RIGHT = LOW;

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
int shroomSensorPins[] = {SHROOM_SENSOR_LEFT_PIN, SHROOM_SENSOR_RIGTH_PIN};

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
    pinMode(SHROOM_SENSOR_RIGTH_PIN, INPUT_PULLUP);
    
    digitalWrite(SHROOM_HOR_POWER_PIN, HIGH);
}

void loop() {
	unsigned long coinCurrentMill = millis();
	unsigned long flowerCurrentMill = millis();
	unsigned long shroomCurrentMill = millis();

    digitalWrite(SHROOM_HOR_POWER_PIN, LOW);

	if(digitalRead(COIN_PUSH_PIN)){
		if(machineCoinState == STATE_COIN_DOWN){
			machineCoinState = STATE_COIN_UP;
                        Serial.println("Up");
			digitalWrite(COIN_MOTOR_POWER_PIN, HIGH);
			coinPreviousMillis = millis();
		}else{
      if( millis() - coinPreviousMillis > COIN_INTERVAL) {
	      machineCoinState = STATE_COIN_DOWN;
	      digitalWrite(COIN_MOTOR_POWER_PIN, LOW);
              Serial.println("Down");
      }
	  }
	}	
// 
// 	if(digitalRead(FLOWER_PUSH_PIN)){
//		if(machineFlowerState == STATE_FLOWER_DOWN){
//			digitalWrite(FLOWER_MOTOR_POWER_PIN, HIGH);
//			machineFlowerState = STATE_FLOWER_UP;
//			flowerPreviousMillis = millis();
//		}else{
//			if( millis() - flowerPreviousMillis > FLOWER_INTERVAL) {
//				machineFlowerState = STATE_FLOWER_DOWN;
//				digitalWrite(FLOWER_MOTOR_POWER_PIN, LOW);
//			}
//		}
//	}	
// 
//	if(digitalRead(SHROOM_PUSH_PIN)){
//
//	}
}

void readPushButtons(){
     for(int pin=0; pin<3 ; pin++){
         pushButtonValues[pin] = digitalRead(pushButtonPins[pin]);
    }
}

void printPushButtonsValues(){
    for(int pin =0; pin<3 ;pin++){
        Serial.print("pin");
        Serial.print(pin);
        Serial.print("is");
        Serial.print(pushButtonValues[pin]);
        Serial.println();  
    }
}

void handlePushButtonState(){
  if (pushButtonValues[0] > 512 ){ 
        Serial.println("Coin button pushed");
    machineCoinState = STATE_COIN_UP;
  }
  if (pushButtonValues[1]){
        Serial.println("Flower button pushed");
    machineFlowerState = STATE_FLOWER_UP;
  }
  if (pushButtonValues[2]){
        Serial.println("Shroom button pushed");
    machineShroomVerState = STATE_SHROOM_UP;
  }
  delay(1000);
}

/*
	void readCoinSensors(){
		digitalRead(COIN_PUSH_PIN);
	};

	void readFlowerSensors(){
		digitalRead(FLOWER_PUSH_PIN);
	};
*/

void readShroomSensors(){
  digitalRead(SHROOM_PUSH_PIN);
};

void handleCoinState(){
  switch(machineCoinState){
    case STATE_COIN_UP:
      break;
    case STATE_COIN_DOWN:
      break;
    default:
      //do nothing
    break;
  }
};

void handleFlowerState(){
  switch(machineFlowerState){
    case STATE_FLOWER_UP:
      break;
    case STATE_FLOWER_DOWN:
      break;
    default:
      //do nothing
    break;
  }
};

void handleShroomState(){
  switch(machineShroomVerState){
    case STATE_SHROOM_UP:
      break;
    case STATE_SHROOM_DOWN:
      break;
    default:
      break;
  }
  switch(machineShroomHorState){  
    case STATE_SHROOM_LEFT:
      break;
    case STATE_SHROOM_RIGHT:
      break;
    default:
      break;
  }
};

void setCoinMotor( bool direction ){
	digitalWrite(COIN_PUSH_PIN, direction);
}


