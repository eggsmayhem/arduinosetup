//initialize tiltsensor, declare port 

int tiltsensor = 2;

//initialize LED, declare port 9
int led = 9;
void setup() {
  // put your setup code here, to run once:
  // set tiltsensor pin mode to input
  pinMode(tiltsensor, INPUT);
  // set LED pin mode to output
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //conditional logic to write high and low to LED based on binary state of titlsensor
  if (digitalRead(tiltsensor) == 1) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  //delay for stability 
  delay(100);
}
