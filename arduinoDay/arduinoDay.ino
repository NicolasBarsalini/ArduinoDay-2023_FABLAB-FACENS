#include <Ultrasonic.h>
#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>


//defines to Ultrasonic sensor
#define echoSens 11
#define triggerSens 10

//define to capacitive touch sensor
#define touch1yes 4
#define touch2no 5

//define to led pins
#define poster 6
#define qrCode 7

Ultrasonic ultrasonicSens(triggerSens, echoSens); //init the ultrasonic sensor

float ReadUltrasonicSensor();
void playAuidos1();
void playAudios2();
void playAudios3();
void verifyDistanceFromSensor(float distanceFromSensor);

typedef struct sensor{
  float microSec;
  float cm;
}Sensor;

typedef struct question1{
  int yes = 0;
  int no = 0;
}Question1;

typedef struct question2{
  int yes = 0;
  int no = 0;
}Question2;

typedef struct question3{
  int yes = 0;
  int no = 0;
}Question3;

Question1 question1;
Question2 question2;
Question3 question3;
Sensor sensor;

int annulled = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(poster, OUTPUT);
  pinMode(qrCode, OUTPUT);
  pinMode(touch1yes, INPUT);
  pinMode(touch2no, INPUT);
  mp3_set_serial(Serial);  //set Serial for DFPlayer-mini mp3 module 
  mp3_set_volume(15);
  if(EEPROM[0] != 9)
  {

    EEPROM[0] = 9;
    
      EEPROM[1] = question1.yes;
      EEPROM[2] = question1.no;

      EEPROM[3] = question2.yes;
      EEPROM[4] = question2.no;
      
      EEPROM[5] = question3.yes;    
      EEPROM[6] = question3.no;

      EEPROM[7] = annulled;
      
  }
  else
  {
    
    question1.yes = EEPROM[1];
    question1.no = EEPROM[2];
    
    question2.yes = EEPROM[3];
    question2.no = EEPROM[4];

    question3.yes = EEPROM[5];
    question3.no = EEPROM[6];

    annulled = EEPROM[7]; 
  }

}

void loop() {
  // microSec = ultrasonicSens.timing(); 
  float distanceFromSensor = readUltrasonicSensor();
  Serial.print("Distance from UltrasonicSensor: "); Serial.println(distanceFromSensor);
  verifyDistanceFromSensor(distanceFromSensor);

  /*Serial.print("TouchYes: "); Serial.println(digitalRead(touch1yes));
  Serial.print("TouchNo: "); Serial.println(digitalRead(touch2no));*/ //optional!
  delay(500);

  Serial.print("Touches for question1 (YES): "); Serial.println(question1.yes);
  Serial.print("Touches for question1 (NO): "); Serial.println(question1.no);

  Serial.print("Touches for question2 (YES): "); Serial.println(question2.yes);
  Serial.print("Touches for question2 (NO): "); Serial.println(question2.no);

  Serial.print("Touches for question3 (YES): "); Serial.println(question3.yes);
  Serial.print("Touches for question3 (NO): "); Serial.println(question3.no);

  Serial.print("Annuled Interactions: "); Serial.println(annulled);
}