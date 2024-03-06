#include <ArduinoJson.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 2
#include <Keypad_Matrix.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, PIN, NEO_GRBW + NEO_KHZ800);

const byte ROWS = 5;
const byte COLS = 5;
int btnRed = 5;
int btnGreen = 6;
// how the keypad has its keys laid out
/*
const char keys[ROWS][COLS] = {
  { 'A', 'F', 'K', 'P', 'U' },
  { 'B', 'G', 'L', 'Q', 'V' },
  { 'C', 'H', 'M', 'R', 'W' },
  { 'D', 'I', 'N', 'S', 'X' },
  { 'E', 'J', 'O', 'T', 'Y' },
};
*/

 
int ButtonFloors[10];

const char keys[ROWS][COLS] = {
  { 'U', 'V', 'W', 'X', 'Y' },
  {  'P', 'Q', 'R', 'S', 'T' },
  { 'K', 'L', 'M', 'N', 'O' },
  { 'F', 'G', 'H', 'I', 'J' },
  { 'A', 'B', 'C', 'D', 'E' },
};

//const byte rowPins[ROWS] = {7, 8, 9, 10, 11}; //connect to the row pinouts of the keypad
const byte rowPins[ROWS] = { A0, A1, A2, A3, A4 };  //connect to the row pinouts of the keypad
const byte colPins[COLS] = { 8, 9, 10, 11, 12 };    //connect to the column pinouts of the keypad
int blank = -1;
// Create the Keypad
Keypad_Matrix kpd = Keypad_Matrix(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String selctColor = "red";
void keyDown_old(const char which) {
  blank = -1;
  //Serial.print(F("Key down: "));
  //Serial.println(which);
  if (which >= '0' && which <= '9') {
    if (kpd.isKeyDown('A'))
      Serial.println("A is down as well.");
    if (kpd.isKeyDown('B'))
      Serial.println("B is down as well.");
    if (kpd.isKeyDown('C'))
      Serial.println("C is down as well.");
    if (kpd.isKeyDown('D'))
      Serial.println("D is down as well.");
  }
}
StaticJsonDocument<200> doc;
JsonArray array = doc.to<JsonArray>();

void keyDown(const char which) {
  blank = -1;

  int key = -1;
  switch (which) {
    case 'A': key = 0; break;
    case 'B': key = 1; break;
    case 'C': key = 2; break;
    case 'D': key = 3; break;
    case 'E': key = 4; break;
    case 'F': key = 5; break;
    case 'G': key = 6; break;

    case 'H': key = 7; break;
    case 'I': key = 8; break;
    case 'J': key = 9; break;
    case 'K': key = 10; break;
    case 'L': key = 11; break;
    case 'M': key = 12; break;
    case 'N': key = 13; break;

    case 'O': key = 14; break;
    case 'P': key = 15; break;
    case 'Q': key = 16; break;
    case 'R': key = 17; break;
    case 'S': key = 18; break;
    case 'T': key = 19; break;

    case 'U': key = 20; break;
    case 'V': key = 21; break;
    case 'W': key = 22; break;
    case 'X': key = 23; break;
    case 'Y': key = 24; break;
  }

  //Serial.println(key + 1);


if(!isInJson(array, (key + 1))){
array.add(key + 1);
serializeJson(doc, Serial);
}


}

bool isInJson(JsonArray array,int num){
  for(JsonVariant v : array) {
    if(num == v.as<int>() ){
      return true;
    }
  }
  return false;
}


void keyUp(const char which) {
  //Serial.print(F("Key up: "));
  //Serial.println(which);
  /*
  int key = -1;
  switch (which) {
    case 'A': key = 0; break;
    case 'B': key = 1; break;
    case 'C': key = 2; break;
    case 'D': key = 3; break;
    case 'E': key = 4; break;
    case 'F': key = 5; break;
    case 'G': key = 6; break;

    case 'H': key = 7; break;
    case 'I': key = 8; break;
    case 'J': key = 9; break;
    case 'K': key = 10; break;
    case 'L': key = 11; break;
    case 'M': key = 12; break;
    case 'N': key = 13; break;

    case 'O': key = 14; break;
    case 'P': key = 15; break;
    case 'Q': key = 16; break;
    case 'R': key = 17; break;
    case 'S': key = 18; break;
    case 'T': key = 19; break;

    case 'U': key = 20; break;
    case 'V': key = 21; break;
    case 'W': key = 22; break;
    case 'X': key = 23; break;
    case 'Y': key = 24; break;
  }

  //Serial.println(key + 1);


if(!isInJson(array, (key + 1))){
array.add(key + 1);
serializeJson(doc, Serial);
}




 */

 


/*

  if (selctColor == "red") {

    if (strip.getPixelColor(key) == 0) {
      Serial.println("blanik1.");
      //strip.setPixelColor(key, strip.Color(0, 0, 255));
      blank = key;
      selctColor = "blue";

      
    } else {
      blank = -1;
      strip.setPixelColor(key, strip.Color(255, 0, 0));
    }



  } else if (selctColor == "green") {

    if (strip.getPixelColor(key) == 0) {
      Serial.println("blanik2.");
           blank = key;
      selctColor = "blue";
      strip.setPixelColor(key, strip.Color(0, 0, 255));
    } else {
        blank = -1;
      strip.setPixelColor(key, strip.Color(0, 255, 0));
    }


  } else if (selctColor == "blue") {
    Serial.println("OFFF.");
    selctColor = "red";
    strip.setPixelColor(key, strip.Color(0, 0, 0));
  }

  strip.show();
  */
}


void setup() {
  Serial.begin(115200);

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined(__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(50);
  strip.show();  // Initialize all pixels to 'off'

  pinMode(btnRed, INPUT_PULLUP);
  pinMode(btnGreen, INPUT_PULLUP);

  Serial.println("Starting.");
  kpd.begin();
  kpd.setKeyDownHandler(keyDown);
  kpd.setKeyUpHandler(keyUp);
}

void loop() {

  kpd.scan();
  if (!digitalRead(btnRed)) {
    selctColor = "red";
  }

  if (!digitalRead(btnGreen)) {
    selctColor = "green";
  }

if(blank>=0){
   strip.setPixelColor(blank, strip.Color(0, 0, 255));
    strip.show();
     delay(150);
       strip.setPixelColor(blank, strip.Color(50, 50, 50));
    strip.show();
     delay(100);

}
  //Serial.println(digitalRead(btnRed));
  //Serial.println(digitalRead(btnGreen));
}

 

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}