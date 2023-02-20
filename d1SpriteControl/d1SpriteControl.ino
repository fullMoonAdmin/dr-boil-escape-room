bool trigger = false;
  

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 delay(500); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (trigger == false){
    Serial.write(0xFC);
    Serial.write(0x01);
    trigger = true;
  }

}
