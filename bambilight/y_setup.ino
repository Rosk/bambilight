// Program Setup
void setup()
{

  delay(WAITSHORT);               // Wait for booting
  
  pinMode(BTNPIN, INPUT);  // initialize the button pin 7 as input  
  
  Serial.begin(115200);    // Open Serial Port at 115200 bps
  
  while (!Serial)          // Leonardo: Software Serial only... 
  {
    ;                      // wait for serial port to connect. Needed for Leonardo only. 
                           // Else there is no serial output...
  }
  
  // now send to Serial
  Serial.println("Serieller Monitor gestartet"); 
  delay(WAITSHORT);        // wait
  
  strip.begin();          // now send to Strip
  strip.show();           // Initialize all pixels to 'off'  
  
  Serial.println("Strip gestartet"); // Send to Serial
  boardReady();           // Board ready prompt
}
