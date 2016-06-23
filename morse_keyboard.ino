#include <PS2Keyboard.h> //Calling PS2Keyboard library

//These are notes for a melody, not needed for Morse Keyboard

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

/*********************************************************************************************************
Defining variables
*********************************************************************************************************/

const int DataPin = 4;               //Sets digital input pin # 4 to receive data from the keyboard
const int IRQpin =  3;               //Sets clock pin # 3, needed for PWM (Pulse Width Modulation)
const int Digital_Output_Pin = 8;    //Sets digital output pin # 8 for relaying signals to the speaker
unsigned int Error_Frequency = 300;  //Sets error tone frequency to 300 Hz (basically all keys that haven't been assigned to do something yet are defined in PS2Keyboard.h)
unsigned long Error_Duration = 300;  //Sets duration of error tone to 300 milliseconds
byte element_wait=100;               //Sets arbitrary time (100ms) for speed of the Morse code and how long pauses are, modifying speeds or slows down all Morse code
unsigned int Frequency = 700;        //Sets frequency for Morse code keys coming out of speaker at 700 Hz (average range for humans is between 20-20,000 Hz)


/*********************************************************************************************************
Unrelated to Morse Keyboard, just some fun
*********************************************************************************************************/
int melody[] = {NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_DS5,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_B4,
  NOTE_E4,NOTE_G4,NOTE_DS5,NOTE_D5,NOTE_G4,NOTE_B4,
  NOTE_B4,NOTE_FS5,NOTE_F5,NOTE_B4,NOTE_D5,NOTE_AS5,
  NOTE_A5,NOTE_F5,NOTE_A5,NOTE_DS6,NOTE_D6,0
};

int noteDurations[] = {8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,2,8,8,1,
  8,4,8,4,8,8,
  8,8,4,8,4,8,
  4,8,4,8,3
};

int pace = 1450;

/*********************************************************************************************************
Beginning Morse Keyboard
*********************************************************************************************************/



PS2Keyboard keyboard;                //Create the keyboard object. Even though you could create multiple objects, only a single PS2 keyboard is supported by this library.

void setup()
{
  delay(1000);
  keyboard.begin(DataPin, IRQpin);   //Begin the receiving keystrokes. DataPin and IRQpin are the pin numbers where you connected the PS2 keyboard's Data and Clock signals.
}

void loop()
{
  if (keyboard.available())          //Check if a keystroke has been received. Returns true if at least one keystroke.
  {
  
    char c = keyboard.read();        //Read the next keystroke. -1 is returned if no keystrokes have been received. Keystrokes are returned as ASCII characters.
                                     //Special keys are mapped to control characters.
   
    if (c == 11)
    {
      faster();
    }
   
    else if (c == 10)
    {
      slower();
    }
   
    else if (c == 'a')
    {
      dit();dah();
      letter_space();
    }
    else if (c == 'b')
    {
      dah();dit();dit();dit();
      letter_space();
    }
    else if (c == 'c')
    {
      dah();dit();dah();dit();
      letter_space();
    }
    else if (c == 'd')
    {
      dah();dit();dit();
      letter_space();
    }
    else if (c == 'e')
    {
      dit();
      letter_space();
    }
    else if (c == 'f')
    {
      dit();dit();dah();dit();
      letter_space();
    }
    else if (c == 'g')
    {
      dah();dah();dit();
      letter_space();
    }
    else if (c == 'h')
    {
      dit();dit();dit();dit();
      letter_space();
    }
    else if (c == 'i')
    {
      dit();dit();
      letter_space();
    }
    else if (c == 'j')
    {
      dit();dah();dah();dah();
      letter_space();
    }
    else if (c == 'k')
    {
      dah();dit();dah();
      letter_space();
    }
    else if (c == 'l')
    {
      dit();dah();dit();dit();
      letter_space();
    }
    else if (c == 'm')
    {
      dah();dah();
      letter_space();
    }
    else if (c == 'n')
    {
      dah();dit();
      letter_space();
    }
    else if (c == 'o')
    {
      dah();dah();dah();
      letter_space();
    }
    else if (c == 'p')
    {
      dit();dah();dah();dit();
      letter_space();
    }
    else if (c == 'q')
    {
      dah();dah();dit();dah();
      letter_space();
    }
    else if (c == 'r')
    {
      dit();dah();dit();
      letter_space();
    }
    else if (c == 's')
    {
      dit();dit();dit();
      letter_space();
    }
    else if (c == 't')
    {
      dah();
      letter_space();
    }
    else if (c == 'u')
    {
      dit();dit();dah();
      letter_space();
    }
    else if (c == 'v')
    {
      dit();dit();dit();dah();
      letter_space();
    }
    else if (c == 'w')
    {
      dit();dah();dah();
      letter_space();
    }
    else if (c == 'x')
    {
      dah();dit();dit();dah();
      letter_space();
    }
    else if (c == 'y')
    {
      dah();dit();dah();dah();
      letter_space();
    }
    else if (c == 'z')
    {
      dah();dah();dit();dit();
      letter_space();
    }
    else if (c == '1')
    {
      dit();dah();dah();dah();dah();
      letter_space();
    }
    else if (c == '2')
    {
      dit();dit();dah();dah();dah();
      letter_space();
    }
    else if (c == '3')
    {
      dit();dit();dit();dah();dah();
      letter_space();
    }
    else if (c == '4')
    {
      dit();dit();dit();dit();dah();
      letter_space();
    }
    else if (c == '5')
    {
      dit();dit();dit();dit();dit();
      letter_space();
    }
    else if (c == '6')
    {
      dah();dit();dit();dit();dit();
      letter_space();
    }
    else if (c == '7')
    {
      dah();dah();dit();dit();dit();
      letter_space();
    }
    else if (c == '8')
    {
      dah();dah();dah();dit();dit();
      letter_space();
    }
    else if (c == '9')
    {
      dah();dah();dah();dah();dit();
      letter_space();
    }
    else if (c == '0')
    {
      dah();dah();dah();dah();dah();
      letter_space();
    }
    else if (c == ' ')
    {
      word_space();
    }
   
    else if (c == 27)
    {
      jamesbond();
    }
   
    else
    {
     tone(Digital_Output_Pin, Error_Frequency, Error_Duration);      //Unused key at this time
    }
  }
}

void dit()                                        //"Dit" function, for Morse code
{
  digitalWrite(Digital_Output_Pin, HIGH);         //Voltage will be set to the corresponding value: 5V for HIGH, 0V (GND) for LOW; on the "Digital_Output_Pin" you set.
  tone(Digital_Output_Pin, Frequency);            //Generates a square wave of the specified frequency on a pin.
                                                  //A duration can be specified, otherwise the wave continues until a call to noTone().
                                                  //The pin can be connected to a piezo buzzer or other speaker to play tones.
                                                  //Only one tone can be generated at a time. If a tone is already playing on a different pin, the call to tone() will have no effect.
                                                  //If the tone is playing on the same pin, the call will set its frequency.
                                                  //It is not possible to generate tones lower than 31Hz.  (That explains some funky behavior when I tried it)
 
  delay(element_wait);                            //Waits for time specified with "element_wait".
  digitalWrite(Digital_Output_Pin, LOW);          //Setting output pin to LOW means 0V, turns it off.
  noTone(Digital_Output_Pin);                     //Stops the generation of a square wave triggered by tone().
  delay(element_wait);
}

void dah()
{
  digitalWrite(Digital_Output_Pin, HIGH);         //Same as above except 3X longer^^
  tone(Digital_Output_Pin, Frequency);
  delay(element_wait * 3);
  digitalWrite(Digital_Output_Pin,LOW);
  noTone(Digital_Output_Pin);
  delay(element_wait);
}

void letter_space()                               //Sets letter spaces after each letter, shorter than word spaces
{
  delay(element_wait * 2);
}

void word_space()                                 //Sets word spaces, are a bit longer to make it clear for receiver of Morse that it's a different word
{
  delay(element_wait * 6);
}

void faster()                                     //Speeds up Morse code sending by 10 milliseconds until element_wait = 40ms
{
  if (element_wait <=40)
  {
    element_wait = 40;
  }
  else
  {
    element_wait = element_wait - 10;
  }
}

void slower()                                      //Slows down Morse code sending by 10 milliseconds until element_wait = 225ms
{
  if (element_wait >= 225)
  {
    element_wait = 225;
  }
  else
  {
    element_wait = element_wait + 10;
  }
}


/*********************************************************
   Just some fun, wanted to add more but it can all be added easily on your own.  BTW, this was used from website below, all credit goes to that individual.
*********************************************************/

void jamesbond()                           
                                      //All credit for this goes to: http://garagelab.com/profiles/blogs/how-to-use-tone-function-arduino-playing-the-james-bond-theme
{
  for (int Note = 0; Note <54; Note++) {//counter of Notes (54 limit the array)
    int duration = pace/noteDurations[Note];//Adjust duration with the pace of music
    tone(8, melody[Note],duration); //Play note

// to distinguish the notes, set a minimum time between them.
    delay(duration*1.2);
  }
}
