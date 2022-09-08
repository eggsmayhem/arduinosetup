byte noteON = 144; //command note on
int tiltsensor = 2; //set pin for tilt sensor

void setup() {
  //set rate in bits per second (bauds) for serial data transmission
  Serial.begin(9600);
   // set tiltsensor pin mode to input
  pinMode(tiltsensor, INPUT);
}

void loop() {
    //conditional logic to write note on or off based on binary state of titlsensor (1 or 0)
  if (digitalRead(tiltsensor) == 1) {
     MIDImessage(noteON, 60, 1);
  }
  else {
    MIDImessage(noteON, 60, 0);
  }  
}

void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
