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

void setup() {
  Serial.begin(9600);
    //OUTPUT PIN ASSIGNMENTS
    pinMode(COIN_MOTOR_POWER_PIN, OUTPUT);
    pinMode(FLOWER_MOTOR_POWER_PIN, OUTPUT);
    pinMode(SHROOM_HOR_POWER_PIN, OUTPUT);
    pinMode(SHROOM_VER_POWER_PIN, OUTPUT);
    pinMode(SHROOM_HOR_DIR_PIN, OUTPUT);
    pinMode(13, OUTPUT); 
    //INPUT PIN ASSIGNMENTS
    //Push buttons
    pinMode(COIN_PUSH_PIN, INPUT_PULLUP);
    pinMode(FLOWER_PUSH_PIN, INPUT_PULLUP);
    pinMode(SHROOM_PUSH_PIN, INPUT_PULLUP);

    //Shroom stuff
    pinMode(SHROOM_SENSOR_LEFT_PIN, INPUT_PULLUP);
    pinMode(SHROOM_SENSOR_RIGTH_PIN, INPUT_PULLUP);

  digitalWrite( COIN_MOTOR_POWER_PIN, HIGH);     
    digitalWrite(SHROOM_HOR_POWER_PIN, HIGH);
}

void loop(){
   
  if(digitalRead(7)){
    digitalWrite( 13, HIGH);     
  }else{
   digitalWrite( 13, LOW);     
    
  }

}
