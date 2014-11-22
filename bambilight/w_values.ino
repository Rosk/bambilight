// Variables - will change:
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button

char inData[9];             // Allocate some space for the serial string
char inChar = -1;           // Where to store the character read
byte index = 0;             // Index into array; where to store the character

// Strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDCOUNT, PIN, NEO_GRB + NEO_KHZ800);

// define Colornames
uint32_t red = strip.Color(255, 0, 0);
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);

// Blues
uint32_t midnightblue   = strip.Color(25, 25, 112);
uint32_t navy           = strip.Color(0, 0, 128);
uint32_t cornflower     = strip.Color(100, 149, 237);
uint32_t slateblue      = strip.Color(106, 90, 205);
// ... make more colors!

