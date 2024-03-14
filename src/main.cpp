#include <Arduino.h>
#include <Wire.h>

// Lager variabler for x og y
int x = 0;
int y = 0;

void setup() {
  // Starter I2C Bus as Master
  Wire.begin(); 

  // Starter Seriel med pc
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(9); // Starter overføring til addresse 9
  Wire.write(x);              // Sender x verdi 
  Serial.print("Sender X verdi til Mega: ");
  Serial.println(x);
  Wire.endTransmission();    // Stopper overføring til addresse 9

  delay(100); //Liten delay for meldinger

  Wire.requestFrom(9, 1); // Spør om 1 byte fra addresse 9
  if(Wire.available()){
    y = Wire.read(); // Setter y verdi til lest verdi fra melding
    Serial.print("Y verdi fra MEGA: ");
    Serial.println(y);
  }

  x++; // Legger på x verdi for å endre den over tid
  if (x > 5) x = 0; // Reseter x verdi slik at den går i loop
  
  delay(500);
}