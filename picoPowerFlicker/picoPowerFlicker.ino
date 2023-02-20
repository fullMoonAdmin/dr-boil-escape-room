int relayOut = 0;
bool triggered = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(relayOut, OUTPUT);
  digitalWrite(relayOut, LOW);
}

void loop() {
  if(triggered == false){
  digitalWrite(relayOut, HIGH);
  delay(300);
  digitalWrite(relayOut, LOW);
  delay(150);
  digitalWrite(relayOut, HIGH);
  delay(250);
  digitalWrite(relayOut, LOW);
  delay(75);
  digitalWrite(relayOut, HIGH);
  delay(222);
  digitalWrite(relayOut, LOW);
  delay(121);
  digitalWrite(relayOut, HIGH);
  // put your main code here, to run repeatedly:
  triggered = true;
  }

}
