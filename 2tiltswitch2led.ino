//behavior: 2 sensors attached to 2 leds, both light up when sensor is tilted 
//initialize vars and declare ports for tilt sensors and LEDS 

int tiltsensor_1 = 2;
int tiltsensor_2 = 4;
int led_1 = 9; 
int led_2 = 10;

void setup() {
  // put your setup code here, to run once:
  //set mode for all sensors/pins
  pinMode(tiltsensor_1, INPUT); 
  pinMode(tiltsensor_2, INPUT); 
  pinMode(led_1, OUTPUT); 
  pinMode(led_2, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
     if (digitalRead(tiltsensor_1)==1 && digitalRead(tiltsensor_2)== 1){
      digitalWrite(led_1,HIGH);
      digitalWrite(led_2,HIGH);
    }

    else if (digitalRead(tiltsensor_1)==1 && digitalRead(tiltsensor_2)== 0){
      digitalWrite(led_1,HIGH);
      digitalWrite(led_2,LOW);
    }

    else if (digitalRead(tiltsensor_1)==0 && digitalRead(tiltsensor_2)== 1){
      digitalWrite(led_1,LOW);
      digitalWrite(led_2,HIGH);
    }

    else if (digitalRead(tiltsensor_1)==0 && digitalRead(tiltsensor_2)== 0){
      digitalWrite(led_1,LOW);
      digitalWrite(led_2,LOW);
    }

    //add delay for stability
    delay(100);
    

}
