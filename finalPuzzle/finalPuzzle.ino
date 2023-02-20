int magRelay = 17;
int output = 22;
int input = 9;
int contact = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(magRelay, OUTPUT);
 pinMode(output, OUTPUT);
 pinMode(LED_BUILTIN, OUTPUT);

 digitalWrite(output, HIGH);
 pinMode(input, INPUT);
 Serial.begin(9600);
 Serial.println("puzzle ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  contact = digitalRead(input); 
if(contact == HIGH){
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(magRelay, HIGH);
  Serial.println("release mag");
  }
}
