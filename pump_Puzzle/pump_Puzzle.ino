int triggerInput = 2;
int triggerOutput = 12;
int relayLightTrigger = 23;
int relayPumpTrigger = 21;
bool pumpTrigger = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(triggerInput, INPUT);
  pinMode(triggerOutput, OUTPUT);
  pinMode(relayLightTrigger, OUTPUT);
  pinMode(relayPumpTrigger, OUTPUT);

  digitalWrite(triggerOutput,HIGH);
  digitalWrite(triggerInput, LOW);
  Serial.begin(9600);
  Serial.println("Pump Puzzle Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(triggerInput) == HIGH && pumpTrigger == false){
    pumpUpTheJam();
  }
}

void pumpUpTheJam (){
    digitalWrite(relayLightTrigger, HIGH);
    digitalWrite(relayPumpTrigger, HIGH);
    Serial.println("Relays active");
    delay(20000);
    digitalWrite(relayPumpTrigger, LOW);
    digitalWrite(relayLightTrigger, LOW);
    pumpTrigger = true; 
    Serial.println("Relays not active");
    }
