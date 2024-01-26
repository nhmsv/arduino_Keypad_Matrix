/*
 * 
 * Example of using Keypad_Matrix with a 4x4 keypad matrix.
 * 
 */

#include <Keypad_Matrix.h>

const byte ROWS = 5;
const byte COLS = 5;

// how the keypad has its keys laid out
const char keys[ROWS][COLS] = {
  {'U', 'V', 'W', 'X', 'Y'},
 {'P', 'Q', 'R', 'S', 'T'},
 {'K', 'L', 'M', 'N', 'O'},
 {'F', 'G', 'H', 'I', 'J'},
 {'A', 'B', 'C', 'D', 'E'},
};

//const byte rowPins[ROWS] = {7, 8, 9, 10, 11}; //connect to the row pinouts of the keypad
const byte rowPins[ROWS] = {A0, A1, A2, A3, A4}; //connect to the row pinouts of the keypad
const byte colPins[COLS] = {2, 3, 4, 5, 6}; //connect to the column pinouts of the keypad

  // Create the Keypad
Keypad_Matrix kpd = Keypad_Matrix( makeKeymap (keys), rowPins, colPins, ROWS, COLS );

void keyDown (const char which)
  {
  Serial.print (F("Key down: "));
  Serial.println (which);
  if (which >= '0' && which <= '9')
    {
    if (kpd.isKeyDown ('A'))
      Serial.println ("A is down as well.");
    if (kpd.isKeyDown ('B'))
      Serial.println ("B is down as well.");
    if (kpd.isKeyDown ('C'))
      Serial.println ("C is down as well.");
    if (kpd.isKeyDown ('D'))
      Serial.println ("D is down as well.");
    }
  }

void keyUp (const char which)
  {
  Serial.print (F("Key up: "));
  Serial.println (which);
  }


void setup() 
{
  Serial.begin (115200);
  Serial.println ("Starting.");
  kpd.begin ();
  kpd.setKeyDownHandler (keyDown);
  kpd.setKeyUpHandler   (keyUp);
}

void loop() 
{
  kpd.scan ();
}
