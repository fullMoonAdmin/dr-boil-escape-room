int cab1 = 2;
int tile = 3;
int tileCount = 0;
bool tileLastFired = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("Randomizer Ready");
  pinMode(cab1, OUTPUT);  
  pinMode(tile, OUTPUT);
}

void loop()
{
  randomSeed(analogRead(A0));
  int randomNum = random(350);
  int randomFactor = random(1000,3500);
    
  if(randomNum >= 0 && randomNum < 100){
  Serial.println("Fire cab");
  delay(111);
  digitalWrite(cab1, HIGH);
  delay(121);
  digitalWrite(cab1, LOW);
  delay(222);
  digitalWrite(cab1, HIGH);
  delay(118);
  digitalWrite(cab1, LOW);  
  tileLastFired = false;
  delay(randomFactor);  
  }
  
  if((randomNum >= 200 && randomNum <= 300) && (tileCount <= 3) && tileLastFired == false){
  Serial.println("Fire celing");
  digitalWrite(tile, HIGH);
  delay(180);
  digitalWrite(tile, LOW);
  delay(1000);
  digitalWrite(tile, HIGH);
  delay(180);
  digitalWrite(tile, LOW);
  delay(1230);
  digitalWrite(tile, HIGH);
  delay(1600);
  digitalWrite(tile, LOW);
  tileCount++;
  tileLastFired = true;
  Serial.println(tileCount);
  delay(randomFactor);
  }
  else{
  delay(randomFactor);
  }
  }
