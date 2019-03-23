    int reading = 0;
    float BPM = 0.0;
    int buzpin=13;
   #include <LiquidCrystal.h>
    LiquidCrystal lcd(12,11,5,4,3,2);
    void setup(){
      Serial.begin(9600);
      lcd.begin(16,2);
    }
    void loop(){
      digitalWrite(buzpin,LOW);
       reading = analogRead(A0); 
      BPM = (int)(60/(reading/1000.0));       //Change the analog reading into BPM
      if(BPM>100){
        lcd.setCursor(0,0);                  //Set LCD cursor position (column 0, row 0)
        lcd.print("Abnormal");
        Serial.print(BPM);
        noTone(buzpin);
        Serial.println("Abnormal");
       }
       else{
        lcd.setCursor(0,0);               //Set LCD cursor position (column 0, row 0)
        lcd.print("Normal");
        Serial.println("Normal");
       lcd.setCursor(0,1);      //Set LCD cursor position (column 0, row 1)
       Serial.print(40);
        tone(buzpin,100);
       lcd.print("Heartbeat:");           //Print the heartbeat in BPM
      lcd.print(BPM);
      }
      delay(1000);
      lcd.clear();
      
      Serial.print("Heartbeat:");
      Serial.println(BPM);
      
      Serial.flush();  
    }
