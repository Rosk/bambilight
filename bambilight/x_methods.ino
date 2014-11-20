// welcome Greeter
void boardReady()
{
  Serial.println("Zzzzzzz");  
  delay(WAITSHORT);
  Serial.println("LED-FADER gestartet");
  delay(WAITSHORT);
  Serial.println("Das Bambi ist aufgewacht!");  
}


// is this method in use, yet?
// Serial Single-Char Reader
char Comp(char* This) {
    while (Serial.available() > 0) // Don't read unless there you know there is data
    {
        if(index < 9) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    }

    if (strcmp(inData,This)  == 0) 
    {
        for (int i=0;i<9;i++) {
            inData[i]=0;
        }
        index=0;
        return(0);
    }
    else 
    {
        return(1);
    }
}




