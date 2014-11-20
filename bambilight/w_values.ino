// Timer Variables
int timer = 200;

// Variables - will change:
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button

// Variables - will not change:
char inData[9];             // Allocate some space for the serial string
char inChar=-1;             // Where to store the character read
byte index = 0;             // Index into array; where to store the character

// define RGB LED Variables
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

// define Colornames
uint32_t red = strip.Color(255, 0, 0);
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 255, 255);
// ... make more colors!

