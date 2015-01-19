#include <LiquidCrystal.h>
// Initialize interface pins being used for LCD 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

int menuOption = 0;
// keyVal holds a value from 0 to 1023, based on the amount of voltage at bottom of resistor ladder. For now, we set it to 0
// Actual voltage is between 0V and 5V. keyVal holds an integer equal to the voltage divided by 4.88 mV.
// Depending on which switch is pressed, there will be a different voltage reading at the base of the resistor ladder. 
int keyVal = 0;
// Initialize array of audio frequencies to be played
int notes[] = {262, 294, 330, 340, 349};

void setup(){
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop(){
    // When menu option is equal to 0, we are at the "Main Menu", where the LCD tells user which buttons to press to choose between freestyle and tutorial mode
    while(menuOption == 0)
    {
        lcd.clear();
        lcd.print("Hold 1 for:");
        lcd.setCursor(0, 1);
        lcd.print("FreeStyle");
        // Incorporating time delays so that user has sufficient time to read the instruction
        delay(3000);
        lcd.clear();
        lcd.print("Hold 2 for:");
        lcd.setCursor(0, 1);
        lcd.print("Tutorial");
        delay(3000);
        
        // Load keyVal with the reading from bottom of resistor ladder
        keyVal = analogRead(A0);
        
        // If this voltage value measurment is between 5 and 10 units, button one is being pressed
        if (keyVal > 5 && keyVal < 10)
        {
            lcd.clear();
            lcd.print("Freestyle Mode");
            // Change value of menuOption to exit the while loop
            menuOption = 1;
        }
        // If this voltage value measurment is between 500 and 520 units, button two is being pressed
        else if (keyVal > 500 && keyVal < 520)
        {
            lcd.clear();
            lcd.print("Tutorial Mode");
            delay(2000);
            // Change value of menuOption to exit the while loop
            menuOption = 2;
        }
    }
    
    // Based on the option that was chosen above, go into freeStyleMode or tutorialMode
    if (menuOption == 1)
    {
        freeStyleMode();
    }
    else if (menuOption == 2)
    {
        tutorialMode();
    }
}

void freeStyleMode()
{
    while(1)
    {
        // Voltage reading will change depending on which button is pressed, play a different note for a different range of voltage readings
        keyVal = analogRead(A0);
        if (keyVal > 5 && keyVal < 10)
        {
            tone(8, notes[0]);
        }
        else if (keyVal > 500 && keyVal < 520)
        {
            tone(8, notes[1]);
        }
        else if (keyVal > 680 && keyVal < 700)
        {
            tone(8, notes[2]);
        }
        else if(keyVal > 1000 && keyVal < 1005)
        {
            tone(8, notes[3]);
        }
        else if (keyVal == 1023)
        {
            tone(8, notes[4]);
        }
        else
        {
            noTone(8);
        }
    }
}

void tutorialMode()
{
   // You can rearrange the functions for pressing buttons to play whatever song you want. Currently, this order of button presses plays the song "Mary Had A Little Lamb"
    pressButtonThree();
    pressButtonTwo();
    pressButtonOne();
    pressButtonTwo();
    pressButtonThree();
    pressButtonThree();
    pressButtonThree();
    pressButtonTwo();
    pressButtonTwo();
    pressButtonTwo();
    pressButtonThree();
    pressButtonFour();
    pressButtonFour();
    pressButtonThree();
    pressButtonTwo();
    pressButtonOne();
    pressButtonTwo();
    pressButtonThree();
    pressButtonThree();
    pressButtonThree();
    pressButtonTwo();
    pressButtonTwo();
    pressButtonThree();
    pressButtonTwo();
    pressButtonOne();
    lcd.clear();
    lcd.print("Good Job!");
    delay(1000);
    menuOption = 0;
}

void pressButtonOne()
{
    // Display "One" on the LCD, then enter an infinite while loop. Exit while loop if the correct button has been pressed.
    lcd.clear();
    lcd.print("One");
    while (1)
    {
        keyVal = analogRead(A0);
        if (keyVal > 5 && keyVal < 10)
        {
            break;
        }
    }
    // Play the corresponding note for the first button
    tone(8, notes[0]);
    // Incorporate a small time delay to play the note for a sufficient amount of time
    delay(300);
    // Cancel the tone after the time delay
    noTone(8);
}

void pressButtonTwo()
{
    lcd.clear();
    lcd.print("Two");
    while (1)
    {
        keyVal = analogRead(A0);
        if (keyVal > 500 && keyVal < 520)
        {
            break;
        }
    }
    tone(8, notes[1]);
    delay(300);
    noTone(8);
}

void pressButtonThree()
{
    lcd.clear();
    lcd.print("Three");
    while (1)
    {
        keyVal = analogRead(A0);
        if (keyVal > 680 && keyVal < 700)
        {
            break;
        }
    }
    tone(8, notes[2]);
    delay(300);
    noTone(8);
}

void pressButtonFour()
{
    lcd.clear();
    lcd.print("Four");
    while (1)
    {
        keyVal = analogRead(A0);
        if (keyVal > 1000 && keyVal < 1005)
        {
            break;
        }
    }
    tone(8, notes[3]);
    delay(300);
    noTone(8);
}

void pressButtonFive()
{
    lcd.clear();
    lcd.print("Five");
    while (1)
    {
        keyVal = analogRead(A0);
        if (keyVal == 1023)
        {
            break;
        }
    }
    tone(8, notes[3]);
    delay(300);
    noTone(8);
}
