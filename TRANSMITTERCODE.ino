const char* MorseTable[] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    // space, !, ", #, $, %, &, '
    NULL, "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
    // ( ) * + , - . /
    "-.--.", "-.--.-", NULL, ".-.-.", "--..--", "-....-", ".-.-.-", "-..-.",
    // 0 1 2 3 4 5 6 7
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    // 8 9 : ; < = > ?
    "---..", "----.", "---...", "-.-.-.", NULL, "-...-", NULL, "..--..",
    // @ A B C D E F G
    ".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    // H I J K L M N O
    "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
    // P Q R S T U V W
    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
    // X Y Z [ \ ] ^ _
    "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, "..--.-",
    // ' a b c d e f g
    NULL, ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    // h i j k l m n o
    "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
    // p q r s t u v w
    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
    // x y z { | } ~ DEL
    "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, NULL,
};

int dotLength = 50;
int dashLength = dotLength * 3;

void setup() {
    pinMode(13, OUTPUT);  // Set pin 13 as output
    pinMode(8, OUTPUT);   // Set pin 8 as output
    pinMode(7, OUTPUT);   // Set pin 7 as output
    Serial.begin(9600);   // Start serial communication at 9600 baud
}

void flashDashDot(const char* morseCode) {
    int i = 0;
    while (morseCode[i] != '\0') {   // Loop until the end of the morse code string
        if (morseCode[i] == '.') {
            dot();                   // Call the dot function
        } else if (morseCode[i] == '-') {
            dash();                  // Call the dash function
        }
        i++;                          // Move to the next character in the string
    }
}

void loop() {
    char ch;
    if (Serial.available()) {         // Check if data is available to read
        ch = Serial.read();           // Read one character from the serial port

        // Ensure the character is within the valid range of the Morse table
        if (ch >= 0 && ch < sizeof(MorseTable) / sizeof(MorseTable[0]) && MorseTable[ch] != NULL) {
            flashDashDot(MorseTable[ch]);  // Flash the corresponding morse code
            delay(dotLength * 2);          // Add a delay between characters
        } else {
            Serial.println("Unsupported character."); // Handle unsupported characters
        }
    }
}

void dot() {
    digitalWrite(13, HIGH);  // Turn on the LEDs
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    delay(dotLength);        // Wait for the duration of a dot
    digitalWrite(13, LOW);   // Turn off the LEDs
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    delay(dotLength);        // Inter-dot gap
}

void dash() {
    digitalWrite(13, HIGH);  // Turn on the LEDs
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    delay(dashLength);       // Wait for the duration of a dash
    digitalWrite(13, LOW);   // Turn off the LEDs
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    delay(dotLength);        // Inter-dash gap
}
