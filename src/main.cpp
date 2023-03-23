#include <Arduino.h>

static float zadnje;
static float srednja[8];
static float br;

void setup() { 
  Serial.begin(9600);
  zadnje = 0;
}

float analogTomVolt(float analog){
  float volt = 1000 * analog * 5 / 1023;
  return volt;
}

float analogToTemp(){
  float temp = (analogRead(A0) * (5000 / 1024.0)) / 10;
  return temp;
}

void loop() {
  float time = millis() / 1000;
  float Cell1 = analogTomVolt(analogRead(A1));
  float Cell2 = analogTomVolt(analogRead(A2));
  float Cell3 = analogTomVolt(analogRead(A3));
  float Cell4 = analogTomVolt(analogRead(A4));
  float Cell5 = analogTomVolt(analogRead(A5));
  float Cell6 = analogTomVolt(analogRead(A6));
  float Cell7 = analogTomVolt(analogRead(A7));
  float Cell8 = analogTomVolt(analogRead(A8));
  
  if (time >= zadnje + 60){
    Serial.print(time);
    for (int j = 0; j < 8; j++){
      String temp1 = (String) (j + 1);
      String temp = " - " + temp1 + " - ";
      Serial.print(temp);
      Serial.print(srednja[j] / br);
    }
    Serial.print(" - Temperatura: ");
    Serial.println(analogToTemp());
    zadnje += 60;
    br = 0;
    for (int i = 0; i < 8; i++){
      srednja[i] = 0;
    }
  } else {
    srednja[0] += Cell1;
    srednja[1] += Cell2;
    srednja[2] += Cell3;
    srednja[3] += Cell4; 
    srednja[4] += Cell5;
    srednja[5] += Cell6;
    srednja[6] += Cell7;
    srednja[7] += Cell8;
    br += 1;
  }
  delay(3000);
}