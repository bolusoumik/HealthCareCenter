
int buzpin=13;
int PIRpin=8;
int pirState = LOW;
int val=0;
int photocellPin=0;
int photocellReading;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  pinMode(buzpin,OUTPUT);
  pinMode(PIRpin,INPUT); 
  noTone(buzpin);               //Initially buzzer remains off
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(2,0);               //Set LCD cursor position (column 2, row 0)
  lcd.print("P.I.R. Motion");
  lcd.setCursor(0,1);               //Set LCD cursor position (column 0, row 1)
  lcd.println("and Light Sensor");
  delay(2000);
  lcd.clear();
    lcd.setCursor(0,0);               //Set LCD cursor position (column 0, row 0)
    lcd.print("Processing data");
    delay(2000);
  lcd.clear();
    lcd.setCursor(3,0);                 //Set LCD cursor position (column 3, row 0)
    Serial.println("NO Motion");
    lcd.print("NO Motion! ");           //Prints "No motion"
    lcd.setCursor(3,1);                 //Set LCD cursor position (column 3, row 1)
    Serial.println("Waiting!");
      lcd.println("Waiting!");          
}

void loop(){
  val = digitalRead(PIRpin);          //Taking input
  if (val == HIGH) {            // check if the input is HIGH
    delay(150);

    if (pirState == LOW) {
        tone(buzpin,100);           //buzzer starts ringing
      Serial.println("Motion detected!");     
      lcd.clear() ;
      lcd.setCursor(0, 0);                 // Set LCD cursor position (column 0, row 0)
      lcd.print("Motion Detected!");        //Prints "Motion Detected
       pirState = HIGH;
          delay(2000) ;
    }
  } else {
    noTone(buzpin);                     //buzzerstops ringing
    // display no motion screen saver
    scrollScreenSaver() ;
      if (pirState == HIGH){
      // There's no motion !
    
      // change to no motion detected
      pirState = LOW;
      }
  }
}

void scrollScreenSaver() {
  
  // autoscroll https://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll
  lcd.clear() ;
    lcd.setCursor(15, 0);         // Set LCD cursor position (column 15, row 0)
    Serial.print("No Motion ");   
  lcd.print("No Motion "); 
  delay(500);  
  lcd.setCursor(15, 1);         //Set LCD cursor position (column 15, row 1)
  Serial.println("Waiting !"); 
   lcd.println("Waiting !"); 
          // scroll 7 positions (display length - string length) to the left to move it back to center:
  
   for (int positionCounter = 0; positionCounter < 22; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
    
   }
}
  
