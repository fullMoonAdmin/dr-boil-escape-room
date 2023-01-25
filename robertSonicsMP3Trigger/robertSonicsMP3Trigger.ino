int track01= 15;
int track02= 2;
int track03= 4;
int track04= 5;
int track05= 18;
int track06= 19;
int track07= 21;
int track08= 22;
int track09= 23;
int track10= 32;

int ambiant01= 12;
int ambiant02= 13;

/* serial setup */
const byte numChars = 4;
char receivedChars[numChars];
boolean newData = false;

void setup() {
  pinMode(track01, OUTPUT);
 pinMode(track02, OUTPUT);
 pinMode(track03, OUTPUT);
 pinMode(track04, OUTPUT);
 pinMode(track05, OUTPUT);
 pinMode(track06, OUTPUT);
 pinMode(track07, OUTPUT);
 pinMode(track08, OUTPUT);
 pinMode(track09, OUTPUT);
 pinMode(track10, OUTPUT);
 pinMode(ambiant01, OUTPUT);
 pinMode(ambiant02, OUTPUT);

 
 digitalWrite(track01, HIGH);
 digitalWrite(track02, HIGH);
 digitalWrite(track03, HIGH);
 digitalWrite(track04, HIGH);
 digitalWrite(track05, HIGH);
 digitalWrite(track06, HIGH);
 digitalWrite(track07, HIGH);
 digitalWrite(track08, HIGH);
 digitalWrite(track09, HIGH);
 digitalWrite(track10, HIGH);
 digitalWrite(ambiant01, HIGH);
 digitalWrite(ambiant02, HIGH);


  
  Serial.begin(9600);
  Serial2.begin(9600);
 
  Serial.println("Arduino is Ready !");
}

void loop() {
  
    recvWithStartEndMarkers();
    showNewData();
 
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
    while (Serial2.available() > 0 && newData == false) {
        rc = Serial2.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        

        if (strcmp(receivedChars, "p01")==0){
          digitalWrite(track01, LOW);
          Serial.println("Track 1 is Playing");
          
            }
        if (strcmp(receivedChars, "p02")==0){
          digitalWrite(track01, HIGH);
          digitalWrite(track02, LOW);
          Serial.println("Track 2 is Playing");
          
            }            
        if (strcmp(receivedChars, "p03")==0){
          digitalWrite(track03, LOW);
          Serial.println("Track 3 is Playing");
          delay(500);
          digitalWrite(track03, HIGH);
            }
        if (strcmp(receivedChars, "p04")==0){
          digitalWrite(track04, LOW);
          Serial.println("Track 4 is Playing");
          delay(500);
          digitalWrite(track04, HIGH);
            }
        if (strcmp(receivedChars, "p05")==0){
          digitalWrite(track05, LOW);
          Serial.println("Track 5 is Playing");
          delay(500);
          digitalWrite(track01, HIGH);
            }
        if (strcmp(receivedChars, "p06")==0){
          digitalWrite(track06, LOW);
          Serial.println("Track 6 is Playing");
          delay(500);
          digitalWrite(track06, HIGH);
            }
        if (strcmp(receivedChars, "p07")==0){
          digitalWrite(track07, LOW);
          Serial.println("Track 7 is Playing");
          delay(500);
          digitalWrite(track07, HIGH);
            }
        if (strcmp(receivedChars, "p08")==0){
          digitalWrite(track08, LOW);
          Serial.println("Track 8 is Playing");
          delay(500);
          digitalWrite(track08, HIGH);
            }
        if (strcmp(receivedChars, "p09")==0){
          digitalWrite(track09, LOW);
          Serial.println("Track 9 is Playing");
          delay(500);
          digitalWrite(track09, HIGH);
            }
        if (strcmp(receivedChars, "p10")==0){
          digitalWrite(track10, LOW);
          Serial.println("Track 10 is Playing");
          delay(500);
          digitalWrite(track10, HIGH);
            }        
        }
        newData = false;
    }
