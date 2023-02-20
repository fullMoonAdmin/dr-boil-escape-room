int cab1 = 2;
int cab2 = 3;
int tile = 4;

void setup()
{
  Serial.begin(9600);
  Serial.println("Randomizer Ready");
  pinMode(cab1, OUTPUT);
  pinMode(cab2, OUTPUT);
  pinMode(tile, OUTPUT);
}

void loop()
{
  randomSeed(analogRead(A0));
  int randomNum = random(450);
  int randomFactor = random(1000,3500);
    
  if(randomNum >= 0 && randomNum < 100){
  Serial.println("fire cab 1");
  digitalWrite(cab1, HIGH);
  delay(100);
  digitalWrite(cab1, LOW);
  delay(250);
  digitalWrite(cab1, HIGH);
  delay(125);
  digitalWrite(cab1, LOW);
  delay(210);
  digitalWrite(cab1, HIGH);
  delay(95);
  digitalWrite(cab1, LOW);  
  delay(randomFactor);
  }
  if(randomNum >= 100 && randomNum < 200){
  Serial.println("Fire cab 2");
  digitalWrite(cab2, HIGH);
  delay(110);
  digitalWrite(cab2, LOW);
  delay(266);
  digitalWrite(cab2, HIGH);
  delay(116);
  digitalWrite(cab2, LOW);
  delay(222);
  digitalWrite(cab2, HIGH);
  delay(111);
  digitalWrite(cab2, LOW);  
    delay(randomFactor);
  }
  if(randomNum >= 200 && randomNum <= 300){
  Serial.println("Fire Scare3");
  digitalWrite(tile, HIGH);
  delay(99);
  digitalWrite(tile, LOW);
  delay(123);
  digitalWrite(tile, HIGH);
  delay(200);
  digitalWrite(tile, LOW);
  delay(188);
  digitalWrite(tile, HIGH);
  delay(112);
  digitalWrite(tile, LOW);
    delay(randomFactor);
  }
  else{
  delay(randomFactor);
  }
  }
