#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#define ONE_WIRE_BUS 6
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celcius=0;
float Fahrenheit=0;

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  lcd.begin(16,2);
 lcd.setCursor(2,0);                    //Set LCD cursor position (column 2, row 0)
  }

void loop(void)
{
  sensors.requestTemperatures();
   delay(1000);
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  lcd.clear() ;
      lcd.setCursor(0, 0);                 // Set LCD cursor position (column 0, row 0)
      lcd.print("Temp: "); 
  Serial.print("C: ");
  lcd.print(Celcius);               //Print the temperature in celsius
  lcd.print(" C ,");
  
  Serial.print("F:");
  lcd.setCursor(0, 1);                  // Set LCD cursor position (column 0, row 1)
  lcd.println(Fahrenheit);              //Print the temperature in Fahrenheit
  lcd.print(" F");
  delay(1000);
  }
