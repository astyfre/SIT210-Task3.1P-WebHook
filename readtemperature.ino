#include <Grove_Temperature_And_Humidity_Sensor.h>

#define DHTPIN D2

DHT dht(DHTPIN);

void setup(){
    Serial.begin(9600);
    dht.begin();
}

void loop(){
    float floatTemp = dht.getTempCelcius();
    
    String temp = String(floatTemp);
    
    Particle.publish("temp", temp, PRIVATE);
    
    delay(3000);
}