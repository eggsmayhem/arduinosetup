
byte noteON = 144; //command note on

void setup() {
  //set rate in bits per second (bauds) for serial data transmission
  Serial.begin(9600);
}

void loop() {
  MIDImessage(noteON, 60, 1);
  delay(300);
  MIDImessage(noteON, 60, 0);
  delay(200);
  
}

void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
