// Main Loop
  // Some example procedures showing how to display to the pixels:
  //  colorWipe(strip.Color(255, 0, 0), 50); // Red
  //  colorWipe(strip.Color(0, 255, 0), 50); // Green

  // Send a theater pixel chase in...
  //  theaterChase(strip.Color(127, 127, 127), 50); // White
  //  theaterChase(strip.Color(127,   0,   0), 50); // Red
  //  theaterChase(strip.Color(  0,   0, 127), 50); // Blue
  
  // Available BAMBI Methods
  //  allOff(wait)
  //  allOn(wait)  
  //  ColorWipe(c,wait)
  //  rainbow(wait)
  //  rainbowCycle(wait)
  //  theaterChase(c,wait) 
  //  theaterChaseRainbow(wait)
  //  Wheel(WheelPos)
  //  starBurst(c,wait)
  //  dualBurst(c,c2,wait)
  
void loop()
{  
  // Initial Loop Status
  String farbe = "";
  String mode = "";
  char character;
  uint8_t m = 0;
  uint8_t farbwert = 0;
  uint8_t farbwertneu = 0;
  uint8_t f1,f2,f3 = 0;
  boolean isrunning = false;

  // Serial Listener
  // read the serial input if there is serial input
  while(Serial.available() > 0) 
  {
      /* 
          Serial Protocol Structure - 9 Chars
          RRRGGGBBBM
          0000000000 = all off, mode0 (off)
          2552552551 = all on,  mode1 (on)
      */
      
      isrunning = true;
      character = Serial.read();
      delay(WAITMICRO);
      farbe.concat(character);
      delay(WAITMICRO);
      index += 1;
      
    // get R
    if (index == 3 && isrunning == true) 
    {
      Serial.println(farbe);
      f1 = farbe.toInt(); 
      farbwertneu +=  f1;
      farbe = "";
      delay(WAITMICRO);
    }      
    // get G
    if (index == 6 && isrunning == true) 
    {
      Serial.println(farbe);
      f2 = farbe.toInt();
      farbwertneu +=  f2;    
      farbe = "";
      delay(WAITMICRO);
    } 
    // get B
    if (index == 9 && isrunning == true) 
    {
      Serial.println(farbe);
      f3 = farbe.toInt();
      farbwertneu +=  f3;    
      farbe = "";
      delay(WAITMICRO);     
    } 
    // get MODE
    if (index == 10 && isrunning == true) 
    {
      mode.concat(character);      
      m = mode.toInt(); // m is now the switch for the playmode trigger
 
      // MODE START
      // run switch here
      bambiSwitch(f1,f2,f3,m,100);      
      delay(100);
      
      // RESET
      index = 0;         // reset index
      mode  = "";        // reset mode
      isrunning = false; // runcycle off
      Serial.write("READY");
    }       

  }  
  
  delay(WAITMICRO);      // wait
}


// Bambi Switch - Start the LED Methods
void bambiSwitch(int r, int g, int b, int m, int t){
 if(m==0){
   allOff(t);
   delay(WAITMICRO);      // wait
 }
 else if(m==1){
   allOn(t);
   delay(WAITMICRO);      // wait
 }
 else if(m==2){
   colorWipe(strip.Color(r, g, b),t);
   delay(WAITMICRO);      // wait
 }
 else if(m==3){
   rainbowCycle(t);
   delay(WAITMICRO);      // wait
 }
 else if(m==4){
   theaterChase(strip.Color(r, g, b),t);
   delay(WAITMICRO);      // wait
 }
 else if(m==5){
   rainbow(t);
 }
 else if(m==6){
   Wheel(20);
   delay(50);
   Wheel(40);
   delay(50);
   Wheel(60);
   delay(50);
   Wheel(80);
   delay(50);
   Wheel(100);
   delay(50);   
 }
 else if(m==7){
   Breath(strip.Color(r, g, b), strip.Color(g, b, r), t, 255);
 }
 else if(m==8){
   // free slot - make more effects
 }
 else if(m==9){
   // free slot - make more effects 
 }
}


