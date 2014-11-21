// Welcome Greeter
void boardReady()
{
  Serial.println("Zzzzzzz");  
  delay(WAITSHORT);
  Serial.println("LED-FADER gestartet");
  delay(WAITSHORT);
  Serial.println("Das Bambi ist aufgewacht!");  
}


// Serial Single-Char Reader
char Comp(char* This) {
    while (Serial.available() > 0) // Don't read unless there you know there is data
    {
        if(index < (SERIALCNT-1)) // One less than the size of the array
        {
            inChar = Serial.read(); // read a character
            inData[index] = inChar; // store it in inData
            index++; // increment index
            inData[index] = '\0'; // Null - terminate the string
        }
    }

    if (strcmp(inData,This)  == 0) 
    {
        for (int i=0; i < (SERIALCNT-1); i++) {
            inData[i] = 0;
        }
        index = 0;
        return(0);
    }
    else 
    {
        return(1);
    }
}
