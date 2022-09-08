// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

//What this version does: discrete notes with some intersting overlap. It's kinda playing too many notes at a time, though. 
//Goal for this version: louder volume and only turn note off when distance changes
//I want louder volume and the note to turn off only when the distance changes

//eventually add potentiometer to simulate heartrate (e.g. how long the delay is, i.e. the tempo of the song) 
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04 
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int temp; //variable to store distance info to see if it has changed each cycle
byte noteON = 144; //command note on

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
//  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
//  Serial.println("with Arduino UNO R3");
}
void loop() {
  //Clear note 
  //if you don't clear the note at the beginning, you get an interseting layered effect. Could play around with this.
//  MIDImessage(noteON, distance, 0);
//  MIDImessage(noteON, 60, 0);
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2 + 30; // Speed of sound wave divided by 2 (go and back). Also, add 30 to distance for note, because notes below 30 are too low to be audible while velocity is one
  
  // Displays the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");

//if hand is present (distance is less than ceiling level + 30), note on at one to one match with distance in centimeters sent to MIDI function
  if (distance < 180) {
    MIDImessage(noteON, distance, 30);
    if (temp != distance) {
    delay(300);  
    MIDImessage(noteON, temp, 0);
  }
  }
  //else if hand is removed, turn note off by setting velocity (volume) to 0
  else {
    MIDImessage(noteON, 60, 0);
  }
   delay(300);
   temp = distance;
   
}

////function for single MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
