#define SensorPin A0 //Constante SensorPin sur A0
#define ms 100 //Constante ms pour le taux de rafraichissement en millisecondes de la loop 
#define contrast 60 //Contraste de l'ecran LCD

#include <LiquidCrystal.h>; //Importation de la librairie pour utiliser le LCD


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Definir les broches du LCD

float sensorValue; //Creation de la variable sensorValue pour capturer ensuite la valeur du capteur hygrometre qui va de 0 a 1023 
String condition; //Creation de la variable condition qui va avoir le type de sol


//Fonction d'initialisation
void setup() { 
  analogWrite(6, contrast); //Definir le contraste sur l'ecran LCD
  lcd.begin(16, 2); //Demarrer l'ecran LCD
  Serial.begin(9600); //Baud rate a 9600 hz
} 


//Fonction principale qui ce repete
void loop() {
  sensorValue = analogRead(SensorPin); //Capturer la valeur du capteur de 0 a 1023 

  // Entre 0 et 35 : Air ambient
  // Entre 36 et 300 : Sol sec
  // Entre 301 et 700 : Sol humide
  // Entre 701 et 950 : Immerger
  // Toute la documentation des valeurs : https://wiki.seeedstudio.com/Grove-Moisture_Sensor/
  
  if (sensorValue >= 0 and sensorValue <= 35){
    condition="   Air ambient";
    }
    
  if (sensorValue > 36 and sensorValue <= 300){
    condition="    Sol sec";
    }
    
  if (sensorValue > 301 and sensorValue <= 700){
    condition="   Sol humide";
    }
    
  if (sensorValue > 701 and sensorValue <= 950){
    condition="    Immerger";
    }

  lcd.clear(); //Effacer l'LCD
  lcd.setCursor(0,0); //Mettre le curseur sur X : 0 ; Y : 0
  lcd.print(condition); //Afficher la variable condition
  lcd.setCursor(0,1); //Mettre le curseur sur X : 0 ; Y : 1
  // Afficher la valeur entre 0 et 950 que le capteur envoye a la broche
  lcd.print(lcd.print(String("    ") + String(sensorValue) + String("/950") + String("    ")));
  delay(ms); //Attendre
}
