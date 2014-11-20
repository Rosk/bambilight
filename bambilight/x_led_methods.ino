// On-Method
void allOn(uint8_t wait){
    for (int i=0; i < strip.numPixels(); i=i+1) 
    {
       strip.setPixelColor(i, 250);        //turn every pixel on      
    }
    strip.show();
    delay(wait);
}

// Off-Method
void allOff(uint8_t wait){
    for (int i=0; i < strip.numPixels(); i=i+1) 
    {
       strip.setPixelColor(i, 0);        //turn every pixel off      
    }
    strip.show();
    delay(wait);
}


// Method 1 - ColorWipe
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}



// Method 2 - Rainbow
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}



// Method 3 - Equal Rainbow
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}



// Method 4 - Theater1
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}



// Method 5 - Theater 2
//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}


// Method 6 - Colorwheel
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}



// Method 7 - StarBurst
void starBurst(uint32_t c, uint8_t wait) {
    for (int j=0; j < 10; j++) {     // cycle 10 colors in the wheel
     for(int k=0; k < 24; k++)
     {
        
      for (int q=0; q < 8; q++) 
      {
        for (int i=0; i < strip.numPixels(); i=i+2) 
        {
          strip.setPixelColor(i+q, Wheel( (i+j+k) % 255));    //turn every second pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+4) 
        {
          strip.setPixelColor(i+q, 0);        //turn every fourth pixel off
        }
        
      }
    }
    }
  }

// Method 7 - DualBurst  
void dualBurst(uint32_t c, uint32_t c2, uint8_t wait) {
   for (int i=0; i < 11; i=i+1) 
    {
      strip.setPixelColor(i, c-(i));    //turn every second pixel on        
    }  
    for (int i=12; i < strip.numPixels(); i=i+1) 
    {
      strip.setPixelColor(i, c2+(i));    //turn every second pixel on                
    }   
    strip.show();    
    delay(wait);     
}

// Method 8 - Breath  
void Breath(uint32_t c1, uint32_t c2, uint8_t wait, uint8_t count) {
 
  for(int ct=0; ct < count; ct = ct+1){
 
    for (int i=0; i < 5; i = i+1) 
    {
      strip.setPixelColor(i, c1);    //turn every second pixel on
      strip.setBrightness(255-ct);      
      strip.show();  
      delay(10);  
  }  
    for (int i=10; i < strip.numPixels()-5; i=i+1) 
    {
      strip.setPixelColor(i, c2);    //turn every second pixel on
      strip.setBrightness(0+ct);      
      strip.show();
      delay(10);  
  }     
    delay(wait);  
  }  
}
