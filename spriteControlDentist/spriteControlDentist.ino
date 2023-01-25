int output = 22;
int input = 2;

bool trigger = false;
void setup() {
  pinMode(output, OUTPUT);
  pinMode(input, INPUT);
  digitalWrite(output, HIGH);
  
 Serial.begin(9600);
 Serial2.begin(9600);
 delay(500);
 Serial.println("The Video Controller is ready!");
}

void loop() {
if ((digitalRead(input)==HIGH)&&trigger == false){
Serial2.write(0xFC);
Serial2.write(0x01);
Serial.write("Switch Video");
trigger = true;
}
}
