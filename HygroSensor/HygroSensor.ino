#define SensorPin A0
#include <LiquidCrystal.h>;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float sensorValue = 0;

int contrast=60 ;

String condition;

void setup() { 
  analogWrite(6, contrast);
  lcd.begin(16, 2);
  Serial.begin(9600);
} 



void loop() {
  sensorValue = analogRead(SensorPin); 
  Serial.println(sensorValue);
  if (sensorValue >= 0 and sensorValue <= 35){
    condition="Air ambient";
    }
  if (sensorValue > 36 and sensorValue <= 300){
    condition="Sol sec";
    
    }
  if (sensorValue > 301 and sensorValue <= 700){
    condition="Sol humide";
    
    }
  if (sensorValue > 701 and sensorValue <= 950){
    condition="Immerger";
    
    }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(condition);
  delay(250);
}
