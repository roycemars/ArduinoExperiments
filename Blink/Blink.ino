/*
  Blink SOS with onboard LED
*/

const int DOT_DURATION = 1000;
const int DASH_DURATION = 3000;
const int SPACE_BETWEEN_DOTS_DURATION = 1000;
const int SPACE_BETWEEN_LETTERS_DURATION = 3000;
const int SPACE_BETWEEN_WORDS_DURATION = 7000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  sos();
}

/**
The SOS signal in Morse code is transmitted by sending three dots, three dashes, and then three more dots, with no spaces between the letters. 
The timings for each element of the SOS signal are:
- Dot: One second long
- Dash: Three seconds long
- Space between dots and dashes within a letter: One second long
- Space between letters: Three seconds long
- Space between words: Seven seconds long 
**/
void sos() {
  // three dots 
  blinkDots(3);

  // three dashes
  blinkDashes(3);
  
  // three more dots
  blinkDots(3);
}

/**
Dot: One second long
Space between dots and dashes within a letter: One second long
**/
void blinkDots(int count) {
  for (int i=0; i<count; i++) {
   blink(DOT_DURATION, SPACE_BETWEEN_DOTS_DURATION);
  }
}

/**
Dash: Three seconds long
Space between dots and dashes within a letter: One second long
**/
void blinkDashes(int count) {
  for (int i=0; i<count; i++) {
   blink(DASH_DURATION, SPACE_BETWEEN_DOTS_DURATION);
  }
}

void delayBetweenLetters() {
  delay(SPACE_BETWEEN_LETTERS_DURATION); 
}

/**
Core logic to blink LED
**/
void blink(int blinkDuration, int spaceDuration) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blinkDuration);                     
  digitalWrite(LED_BUILTIN, LOW);
  delay(spaceDuration);          
}
