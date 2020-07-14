int speakerPin = 9;

int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int led10 = 10;
int led11= 11;
int led12 = 12;
int led13 = 13;

int notes_length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tempo = 150;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
     digitalWrite(speakerPin, HIGH);
     delayMicroseconds(tone);
     digitalWrite(speakerPin, LOW);
     delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           
  
                   'c', 'd', 'e', 'f', 'g', 'a', 'b',
  
                   'x', 'y' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
  
                   956,  834,  765,  593,  468,  346,  224,
  
                   655 , 715 };
  int SPEE = 5;
  int newduration;
  // play the tone corresponding to the note name
  for (int i = 0; i <= 16; i++) {
      if (names[i] == note) {
         newduration = duration/SPEE;
        playTone(tones[i], newduration);
      }
  }

}

void setup() {
  pinMode(speakerPin, OUTPUT);
  
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
}

void loop() {
  //digitalWrite(redLED, HIGH);
  //digitalWrite(yellowLED, HIGH);
  //digitalWrite(greenLED, HIGH);
  for (int i = 0; i < notes_length; i++) {
     if (notes[i] == ' ') {
        digitalWrite(redLED, HIGH);
        digitalWrite(yellowLED, HIGH);
        digitalWrite(greenLED, HIGH);
        digitalWrite(led10, HIGH);
        digitalWrite(led11, HIGH);
        digitalWrite(led12, HIGH);
        digitalWrite(led13, HIGH);
        delay(beats[i] * tempo); // rest
        
     } 
     else {
        playNote(notes[i], beats[i] * tempo);
        //digitalWrite(redLED, LOW);
        //digitalWrite(yellowLED, LOW);
        //digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
        digitalWrite(yellowLED, HIGH);
        digitalWrite(greenLED, HIGH);
        digitalWrite(led10, HIGH);
        digitalWrite(led11, HIGH);
        digitalWrite(led12, HIGH);
        digitalWrite(led13, HIGH);
     }
    delay(tempo);// pause between notes
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(led10, LOW);
    digitalWrite(led11, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led13, LOW);
  }
  //digitalWrite(redLED, LOW);
  //digitalWrite(yellowLED, LOW);
  //digitalWrite(greenLED, LOW);
  
}
