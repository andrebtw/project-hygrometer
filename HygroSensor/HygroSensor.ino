#define SensorPin A0

float sensorValue = 0;


void setup() { 
 Serial.begin(9600); 
} 


void loop() { 
  sensorValue = analogRead(SensorPin); 
  Serial.println(sensorValue);
}
