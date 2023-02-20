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
bool fishPuzzleCheck = false; 
bool triggerClockPuzzle = false; 
bool triggerJarPuzzle = false;
bool triggerPicturePuzzle = false;
bool enterLabRoom = false;
bool startfinalCountdown = false;
bool startDrGiggles = false;

 

void setup() {
 Serial.begin(baud);
 Serial2.begin(baud);
 pinMode(CONTROLLINO_D0, OUTPUT);
 pinMode(CONTROLLINO_D1, OUTPUT);
 pinMode(CONTROLLINO_D2, OUTPUT);
 pinMode(CONTROLLINO_D3, OUTPUT);
 pinMode(CONTROLLINO_D4, OUTPUT);
 pinMode(CONTROLLINO_D5, OUTPUT);
 pinMode(CONTROLLINO_D6, OUTPUT);
 pinMode(CONTROLLINO_D7, OUTPUT);
 pinMode(CONTROLLINO_D8, OUTPUT);

 pinMode(CONTROLLINO_D15, OUTPUT); 
 pinMode(CONTROLLINO_D16, OUTPUT); 
 pinMode(CONTROLLINO_D17, OUTPUT); 
 pinMode(CONTROLLINO_D18, OUTPUT); 
 pinMode(CONTROLLINO_D19, OUTPUT); 
 pinMode(CONTROLLINO_D20, OUTPUT);
 pinMode(CONTROLLINO_D21, OUTPUT);
 pinMode(CONTROLLINO_D22, OUTPUT);
 



 pinMode(CONTROLLINO_D23, OUTPUT);

 pinMode(CONTROLLINO_A0, INPUT);
 pinMode(CONTROLLINO_A1, INPUT);
 pinMode(CONTROLLINO_A2, INPUT);
 pinMode(CONTROLLINO_A3, INPUT);
 pinMode(CONTROLLINO_A4, INPUT);
 pinMode(CONTROLLINO_A5, INPUT);
 pinMode(CONTROLLINO_A6, INPUT);
 pinMode(CONTROLLINO_A7, INPUT);
 pinMode(CONTROLLINO_A8, INPUT);

 
 pinMode(CONTROLLINO_R0, OUTPUT);
 pinMode(CONTROLLINO_R1, OUTPUT);
 pinMode(CONTROLLINO_R2, OUTPUT);
 pinMode(CONTROLLINO_R3, OUTPUT);
 pinMode(CONTROLLINO_R4, OUTPUT);
 pinMode(CONTROLLINO_R5, OUTPUT);
 pinMode(CONTROLLINO_R6, OUTPUT);
 pinMode(CONTROLLINO_R7, OUTPUT);
 pinMode(CONTROLLINO_R8, OUTPUT);
 pinMode(CONTROLLINO_R10, OUTPUT);
 pinMode(CONTROLLINO_R13, OUTPUT);


 pinMode(CONTROLLINO_R15, OUTPUT);


 
 delay(3000);
 digitalWrite(CONTROLLINO_D0, HIGH);
 digitalWrite(CONTROLLINO_D1, HIGH);
 digitalWrite(CONTROLLINO_D2, HIGH);
 digitalWrite(CONTROLLINO_D3, HIGH);
 digitalWrite(CONTROLLINO_D4, HIGH);
 digitalWrite(CONTROLLINO_D5, HIGH);
 digitalWrite(CONTROLLINO_D6, HIGH);
 digitalWrite(CONTROLLINO_D7, HIGH);
 digitalWrite(CONTROLLINO_D8, HIGH);

 digitalWrite(CONTROLLINO_D21, HIGH);

 digitalWrite(CONTROLLINO_R0, HIGH);
 digitalWrite(CONTROLLINO_R1, HIGH); 
 digitalWrite(CONTROLLINO_R4, HIGH);
 digitalWrite(CONTROLLINO_R6, HIGH);
 digitalWrite(CONTROLLINO_R7, HIGH);
 digitalWrite(CONTROLLINO_R15, HIGH);
 Serial.println("Big Brain Ready");
 delay(2000);
 }

void loop() {
  
  if (ambiant1Time.update()){
    playAmbiant1();
      
  }
  if (triggerPicturePuzzle == true){
    sickoMode();
    openLab();
  }
  if (triggerSickoMode == true){
  switchPuzzle();  
    }
  sinkPuzzle();
  phonePuzzle();
  fluidPuzzle();  
  fishPuzzle();
  clockPuzzle();
  picturePuzzle();
  jarPuzzle();
  finalCountdown();
  drGiggles();
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
      Serial.println("Phone Puzzle Triggered");
      digitalWrite(CONTROLLINO_D23, HIGH);
      delay(600);
      digitalWrite(CONTROLLINO_D23, LOW);
      triggerPhonePuzzle = true;      
    }
  }
  void sickoMode() {
    if(digitalRead(CONTROLLINO_A5)== HIGH && triggerSickoMode == false){
      Serial.println("Movement detcted Sicko Mode");      
      digitalWrite(CONTROLLINO_R3, HIGH);
      digitalWrite(CONTROLLINO_R8, HIGH); 
      digitalWrite(CONTROLLINO_D19, LOW);
      digitalWrite(CONTROLLINO_D16, HIGH);
      digitalWrite(CONTROLLINO_D15, HIGH); 
      Serial2.print("<p02>");  
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
      digitalWrite(CONTROLLINO_D21, LOW);
      triggerSwitchPuzzle = true;   
    }
  }
    void fishPuzzle() {
      if(digitalRead(CONTROLLINO_A3)== LOW && triggerFishPuzzle == false){
          Serial.println("fishPuzzleTriggered");
          Serial2.print("<p05>");
          digitalWrite(CONTROLLINO_R15, LOW);
          fishPuzzleCheck= true;                  
          }      
   }
   void clockPuzzle() {
    if(digitalRead(CONTROLLINO_A4)== HIGH && triggerClockPuzzle == false){
          Serial.println("ClockPuzzleTriggered");
          Serial2.print("<p10>");
          digitalWrite(CONTROLLINO_R7, LOW);
          triggerClockPuzzle = true;
      } 
    }
     void picturePuzzle() {
    int pictureSensorValue = analogRead(CONTROLLINO_A13);
    if (pictureSensorValue <= 0 && triggerPicturePuzzle == false ){
       Serial.println("picture Puzzle Triggered");
       Serial2.print("<p08>");
       digitalWrite(CONTROLLINO_D22, HIGH);
       triggerPicturePuzzle = true;       
    }
  }
  void jarPuzzle() {
    if(digitalRead(CONTROLLINO_A6)== HIGH && triggerJarPuzzle == false){
          Serial.println("JarPuzzleTriggered");
          Serial2.print("<p06>");
          digitalWrite(CONTROLLINO_R10, HIGH);
          digitalWrite(CONTROLLINO_D20, HIGH);
          triggerJarPuzzle = true;
      } 
    }
  void openLab () {
    if(digitalRead(CONTROLLINO_A1)== LOW && enterLabRoom == false){
          Serial.println("Lab Open");
          digitalWrite(CONTROLLINO_D19, HIGH);
          enterLabRoom = true;
      }     
    }

    void drGiggles () {
    if(digitalRead(CONTROLLINO_A8)== HIGH && startDrGiggles == false ){
          Serial.println("Giggles Triggered");
          digitalWrite(CONTROLLINO_R2, HIGH);
          delay(100);
          digitalWrite(CONTROLLINO_R2, LOW);
          delay(4900);
          digitalWrite(CONTROLLINO_D17, HIGH);                            
      }     
    }
  void finalCountdown () {
    if(digitalRead(CONTROLLINO_A7)== HIGH && startfinalCountdown == false){
          Serial.println("key activated");
          digitalWrite(CONTROLLINO_R13, HIGH);
          digitalWrite(CONTROLLINO_D18, HIGH);
          delay(20000);
          digitalWrite(CONTROLLINO_R13, LOW);
          digitalWrite(CONTROLLINO_D18, LOW);

                   
      }     
    }
