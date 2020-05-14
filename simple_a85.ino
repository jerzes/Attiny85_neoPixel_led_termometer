#include <Adafruit_NeoPixel.h>
#include <DallasTemperature.h>
#include <OneWire.h>


#define PIN  0
#define NUMPIXELS 45
#define BUTTONPIN 1
#define ANALOG_PIN A1
#define ONE_WIRE_BUS 4
#define DECNUM 44
#define PARTNUM 43

OneWire oneWire(ONE_WIRE_BUS);
 
DallasTemperature sensors(&oneWire); 
int temp = 0;
int sw2 = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  sensors.begin();
  pixels.begin();
  pinMode(BUTTONPIN, INPUT);

}

void orange(){
  for(int i=0; i<NUMPIXELS - 2; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 70));
    pixels.setBrightness(80);
    pixels.show();
}
}

void green(){
  for(int i=0; i<NUMPIXELS - 2; i++) {
    pixels.setPixelColor(i, pixels.Color(153, 204, 0));
    pixels.setBrightness(20);
    pixels.show();
}
}

void white(){
  for(int i=0; i<NUMPIXELS -2; i++) {
    pixels.setPixelColor(i, pixels.Color(200, 210, 210));
    pixels.setBrightness(80);
    pixels.show();
}
}

void bright(){
int sensor = analogRead(ANALOG_PIN);
 if(sensor >=380){
  green();
 }
 if(sensor < 380 && sensor > 100){
  white();
 }
 if(sensor <= 100){
  orange();
 }
}

void setTemp(int temperature){
  short int dec = temperature / 10;
  short int part = temperature % 10;
  switch(dec){
    case 1: 
      pixels.setPixelColor(DECNUM, pixels.Color(0, 128, 255)); //shade blue
      break;
    case 2:
      pixels.setPixelColor(DECNUM, pixels.Color(255, 128, 0)); //yelow
      break;
  }
  
  switch(part){
    case 0:
      pixels.setPixelColor(PARTNUM, pixels.Color(0, 0, 150));
      break;
    case 1:
      pixels.setPixelColor(PARTNUM, pixels.Color(0, 0, 255));
      break;
    case 2:
      pixels.setPixelColor(PARTNUM, pixels.Color(0, 128, 255));
      break;
    case 3:
      pixels.setPixelColor(PARTNUM, pixels.Color(0, 255, 255));
      break;
    case 4:
      pixels.setPixelColor(PARTNUM, pixels.Color(0, 255, 0));
      break;
    case 5:
      pixels.setPixelColor(PARTNUM, pixels.Color(128, 255, 0));
      break;
    case 6:
      pixels.setPixelColor(PARTNUM, pixels.Color(255, 255, 0));
      break;
    case 7:
      pixels.setPixelColor(PARTNUM, pixels.Color(255, 128, 0));
      break; 
    case 8:
      pixels.setPixelColor(PARTNUM, pixels.Color(255, 0, 0));
      break;
    case 9:
      pixels.setPixelColor(PARTNUM, pixels.Color(255, 51, 153));
      break;     
  }
  pixels.show();
}

void loop() {

sensors.requestTemperatures();
int current_temp = (int)sensors.getTempCByIndex(0);   
if(current_temp != temp){
  setTemp(current_temp);
  temp = current_temp;
}

int sw1 = digitalRead(BUTTONPIN);
if(sw1 == 1){
  if(sw2 == 0){
    bright();
    sw2 = 1;
  }else{
    pixels.clear();
    setTemp(current_temp);
    pixels.show();
    sw2 = 0;
  }
}
if(sw2 == 1){
  bright();
}
delay(500);

 
}
