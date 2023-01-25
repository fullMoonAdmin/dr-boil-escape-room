#include <SPI.h>
#include <Controllino.h>
#include <NoDelay.h>

 /*
 *Wireing Guide 
 *R0 = 5v power board
 *R1 = Medicine Cabnet Puzzle Magnet
 *R2 = Sprite Player Power 
 *R3 = Sprite Player Video Trigger
 *R4 = Switch Puzzle Magnet  
 *R5 = Fluid pump puzzle trigger
 * 
 *D0 & A0 = Medicine cabnet Trigger 
 *D1 & A1 = Lab room door trigger
 *D2 & A2 = Fluid pump puzzle button trigger
 *D3 & A3 = Fish puzzle trigger 
 */
int baud = 9600;  
noDelay ambiant1Time(7000);

bool triggerPuzzle1 = false; 
bool triggerAmbiant1 = false;
bool triggerPhonePuzzle = false;
bool triggerSickoMode = false;
bool triggerFluidPuzzle = false;
bool triggerSwitchPuzzle = false; 
bool triggerFishPuzzle = false; 

void setup() {
 Serial.begin(baud);
 Serial2.begin(baud);
 pinMode(CONTROLLINO_D0, OUTPUT);
 pinMode(CONTROLLINO_D1, OUTPUT);
 pinMode(CONTROLLINO_D2, OUTPUT);
 pinMode(CONTROLLINO_D3, OUTPUT);

 pinMode(CONTROLLINO_D23, OUTPUT);

 pinMode(CONTROLLINO_A0, INPUT);
 pinMode(CONTROLLINO_A1, INPUT);
 pinMode(CONTROLLINO_A2, INPUT);
 pinMode(CONTROLLINO_A3, INPUT);
 
 pinMode(CONTROLLINO_R0, OUTPUT);
 pinMode(CONTROLLINO_R1, OUTPUT);
 pinMode(CONTROLLINO_R2, OUTPUT);
 pinMode(CONTROLLINO_R3, OUTPUT);
 pinMode(CONTROLLINO_R4, OUTPUT);
 pinMode(CONTROLLINO_R5, OUTPUT);
 pinMode(CONTROLLINO_R6, OUTPUT);

 
 delay(3000);
 digitalWrite(CONTROLLINO_D0, HIGH);
 digitalWrite(CONTROLLINO_D1, HIGH);
 digitalWrite(CONTROLLINO_D2, HIGH);
 digitalWrite(CONTROLLINO_D3, HIGH);
 digitalWrite(CONTROLLINO_R0, HIGH);
 digitalWrite(CONTROLLINO_R1, HIGH);
 digitalWrite(CONTROLLINO_R2, HIGH);
 digitalWrite(CONTROLLINO_R4, HIGH);
 digitalWrite(CONTROLLINO_R6, HIGH);
 Serial.println("Big Brain Ready");
 delay(2000);
 }

void loop() {
  
  if (ambiant1Time.update()){
    playAmbiant1();
  }
  sinkPuzzle();
  phonePuzzle();
  //sickoMode();
  fluidPuzzle();
  switchPuzzle();
  fishPuzzle();
  

}

void playAmbiant1() {
    if(triggerAmbiant1 == false){
          Serial.println("Ambiant Track Playing");
          Serial2.print("<p01>"); 
          triggerAmbiant1 = true; 
    }    
  }

  void sinkPuzzle() {
    if(digitalRead(CONTROLLINO_A0)== HIGH && triggerPuzzle1 == false){
          Serial.println("Puzzle 1 Track Playing");
          Serial2.print("<p04>");
          digitalWrite(CONTROLLINO_R1, LOW);          
          triggerPuzzle1 = true;
    }    
  }

  void phonePuzzle() {
    int sensorValue = analogRead(CONTROLLINO_A15);
    if (sensorValue <= 0 && triggerPhonePuzzle == false ){
      Serial2.print("<p03>");
      digitalWrite(CONTROLLINO_D23, HIGH);
      delay(600);
      digitalWrite(CONTROLLINO_D23, LOW);
      triggerPhonePuzzle = true;      
    }
  }
  void sickoMode() {
    if(digitalRead(CONTROLLINO_A1)== LOW && triggerSickoMode == false){
      Serial.println("Sicko Mode");      
      digitalWrite(CONTROLLINO_R3, HIGH);    
      triggerSickoMode = true;
      }   
    }

    void fluidPuzzle() {
    if(digitalRead(CONTROLLINO_A2)== HIGH && triggerFluidPuzzle == false){
          Serial2.print("<p07>");
          Serial.println("fluid puzzle triggered");                      
          triggerFluidPuzzle = true;
          digitalWrite(CONTROLLINO_R5, HIGH);
          digitalWrite(CONTROLLINO_R6, LOW);          
    }    
  }
    void switchPuzzle() {
    int switchSensorValue = analogRead(CONTROLLINO_A14);
      if (switchSensorValue >= 300 && triggerSwitchPuzzle == false ){
      digitalWrite(CONTROLLINO_R4, LOW);
      Serial2.print("<p09>"); 
      triggerSwitchPuzzle = true;   
    }
  }
    void fishPuzzle() {
      if(digitalRead(CONTROLLINO_A3)== LOW && triggerFishPuzzle == false){
          Serial.println("fishPuzzleTriggered");
          Serial2.print("<p05>");                  
          triggerFishPuzzle = true;
      }      
   }
