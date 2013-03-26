//OUTPUT PIN ASSIGNMENTS
const int SHROOM_HOR_DIR_PIN = 0;
const int COIN_MOTOR_POWER_PIN = 13;
const int FLOWER_MOTOR_POWER_PIN = 11;
const int SHROOM_HOR_POWER_PIN = A2;
const int SHROOM_VER_POWER_PIN = 2;

//INPUT PIN ASSIGNMENTS
const int SHROOM_SENSOR_LEFT_PIN = 5;
const int SHROOM_SENSOR_RIGHT_PIN = 6 ; 
const int COIN_PUSH_PIN = 12;
const int FLOWER_PUSH_PIN = 8;
const int SHROOM_PUSH_PIN = 9;

const bool LEFT = HIGH;
const bool RIGHT = LOW;

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
  pinMode(SHROOM_SENSOR_RIGHT_PIN, INPUT_PULLUP);

  digitalWrite(COIN_MOTOR_POWER_PIN, HIGH); //Stop coin motor.
  digitalWrite(SHROOM_VER_POWER_PIN, HIGH); //Stop coin motor.
  analogWrite(SHROOM_HOR_POWER_PIN, 0); //Stop coin motor.
  digitalWrite(FLOWER_MOTOR_POWER_PIN, HIGH); //Stop coin motor.
}

void loop(){  

  if ( digitalRead(SHROOM_SENSOR_RIGHT_PIN)){
    Serial.println("HIGH");
        digitalWrite(SHROOM_VER_POWER_PIN, HIGH); // Move the shroom down
  }else{
    Serial.println("LOW");
      digitalWrite(SHROOM_VER_POWER_PIN, LOW); // Move the shroom down
    }

}
