// Author: Matthew Boakes (@MatthewBoakes)
// Edited and Modified: Matt Halliday (@MattHalliday5)
// Edited and Modified: Jake Bryant (@BelatedGames)
// Edited and Modified: Jake Price (@4A50_)

// Install guide and other information in READ ME.txt file.

#include <Conceptinetics.h>

// <---- DMX Configuration ---->

// This master will control 3 channels (1-3)
const uint16_t DMX_MASTER_CHANNELS = 3;
// Pin number to change or read or wirte mode on the sheild.
const int RXEN_PIN = 2;

const uint16_t RED_CHANNEL = 1;
const uint16_t GREEN_CHANNEL = 2;
const uint16_t BLUE_CHANNEL = 3;

const uint8_t MIN_BRIGHTNESS = 0;
const uint8_t MAX_BRIGHTNESS = 255;

// Configure a dmxMaster controller
DMX_Master dmxMaster(DMX_MASTER_CHANNELS, RXEN_PIN);

// Random time
const int ranTime;


const int g;
// <---- LED Configurations ---->

const uint8_t RED_LED = 3;
const uint8_t GREEN_LED = 4;

// Defining ultrasonic pin numbers
const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;

// Defines ultrasonic variables
long duration;
double distance;

void setLED(uint8_t redLEDValue, uint8_t greenLEDValue) {
  digitalWrite(RED_LED, redLEDValue);
  digitalWrite(GREEN_LED, greenLEDValue);
}

void setRGB(uint8_t redIntensity, uint8_t greenIntensity, uint8_t blueIntensity) {
  dmxMaster.setChannelValue(RED_CHANNEL, redIntensity);
  dmxMaster.setChannelValue(GREEN_CHANNEL, greenIntensity);
  dmxMaster.setChannelValue(BLUE_CHANNEL, blueIntensity);
}

void greenOn() {
  // Turning on the green LED
  setLED(HIGH, LOW);
  for(int i = 0; i < 255; i = i + 1){  //ON FADE
    setRGB(int(0), i, int(0));
    delay(15);
  }
  for(int f = 255; f >= 0; f = f - 1){  // OFF FADE
    setRGB(int(0), f, int(0));
    delay(random(1,400));
  }

  blueOn();
  //return 0;
}

void blueOn() {
  // Turning on blue LED
  setLED(HIGH, LOW);
  for(int i = 0; i < 255; i = i + 1){  //ON FADE
    setRGB(int(0), int(0), i);
    delay(15);
  }
  for(int f = 255; f >= 0; f = f - 1){  // OFF FADE
    setRGB(int(0), int(0), f);
    delay(random(1, 400));
  }
  yellowOn();
}

void yellowOn() {
  setLED(HIGH, LOW);
  for(int i = 0; i < 255; i = i + 1){  //ON FADE
    setRGB(i,i, int(0));
    delay(15);
  }
  for(int f = 255; f >= 0; f = f - 1){  // OFF FADE
    setRGB(f, f, int(0));
    delay(random(1, 400));;
  }
  orangeOn();
  //setRGB(int(255), int(199), int(0));
}

void orangeOn() {
  setLED(HIGH, LOW);
  //setRGB(int(255), int(101), int(0));
  for(int i = 0; i < 255; i = i + 1){  //ON FADE
      if(i >= 101){
        int g = 101;
      }else{
        int g = i;
      }
      setRGB(i,g,int(0));
      delay(15);
  }
  for(int f = 255; f >= 0; f = f - 1){  // OFF FADE
      if(f >= 101){
       int g = 101;
      }else{
       int g = f;
      }
      setRGB(f,g,int(0));
      delay(random(1,400));;
  }
  redOn();
}

void redOn() {
  // Turning on the red light
  setLED(HIGH, LOW);
  for(int i = 0; i < 255; i = i + 1){  //ON FADE
    setRGB(i, int(0), int(0));
    delay(15);
  }
  for(int f = 255; f >= 0; f = f - 1){  // OFF FADE
    setRGB(f,int(0),int(0));
    delay(random(1, 400));
  }
  greenOn();
}


void setup() {
  pinMode(TRIG_PIN, OUTPUT); // sets the trig pin as an output
  pinMode(ECHO_PIN, INPUT); // sets the echo pin as input

  pinMode(GREEN_LED, OUTPUT); // sets green led as output
  pinMode(RED_LED, OUTPUT); // sets red led as output

  dmxMaster.enable(); // Enables DMX master interface and starts transmitting

  greenOn();
}



void loop() {
  // Cleaing the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Sets the TRIG_PIN on HIGH state for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

}
