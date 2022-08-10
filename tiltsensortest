//initialize tiltsensor, declare port 

int tiltsensor = 2;
void setup() {
  // put your setup code here, to run once:
  // set tiltsensor pin mode to input
  pinMode(tiltsensor, INPUT);
  //set rate in bits per second (bauds) for serial data transmission
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //print values in Serial Monitor (Tools->Serial Monitor)
  Serial.println(digitalRead(tiltsensor));
  delay(100);

}
