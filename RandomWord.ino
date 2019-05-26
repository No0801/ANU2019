/*
  Hello World.ino
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:Loovee
  2013-9-18

  Grove - Serial LCD RGB Backlight demo.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 0;
bool state = true;

const unsigned int numberOfwords = 25; // has to match the number of words in the array
const char * const wordList[numberOfwords] PROGMEM = {
  "Maison", "Mickey", "Girafe", "Poulpe", "Bateau", "Voiture", "Batman", "Chaise", "Table", "Serpent", "France", "Vache", "Epee", "Collier", "Femme",
  "Homme", "Ballon", "Soleil", "Arbre", "Lapin", "Chat", "Pinnochio", "Chien", "Tshirt",
};
unsigned long randomNumber;
unsigned int pointer;
unsigned int count;
unsigned int exclude[20]; // holds word numbers that recently have been used

int t = 60;
char * Word;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, 255);
    randomSeed(analogRead(0));

    Word = (char *) pgm_read_word (&wordList[random(0,24)]);
    delay(1000);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    // print the number of seconds since reset:
    //lcd.print(millis()/1000);
    
    if (state){
      lcd.setCursor(0,0);
      lcd.print(Word);
      lcd.setCursor(0, 1);
      lcd.print(t);
      lcd.print(" ");
     
    }
    
    
    if (!state){
      lcd.setCursor(0,0);
      lcd.print("Prochain mot");
      lcd.setCursor(0,1);
      lcd.print("dans ");
      lcd.print(t);
      lcd.print(" ");
      lcd.print(" s ");
      
    }
    

    delay(1000);
    t=t-1;
     if(t <= 0 && state){
        state=false;
        t = 10;
        lcd.clear();
        lcd.setRGB(255, colorG, colorB);
      }
      if(t <= 0 && !state){
         t=60;
          state=true;
          lcd.clear();
           Word = (char *) pgm_read_word (&wordList[random(0,24)]);
           lcd.setRGB(0, colorG, 255);
      }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
