#include <Arduino.h>
#include <Wire.h>
#include <UnicViewAD.h>

// Defines Slave Unit (2nd Arduino) I2C Address
#define SLAVE_UNIT_ADDRESS 1

// *******************************************************************************************************************************************
// * Display Init
// *******************************************************************************************************************************************
LCM Lcm(Serial);                 // Init Proculus display


void setup() {
    // setup display
    Lcm.begin();  // Inicia e configura o LCM

    // setup I2C
    Wire.begin();

    // setup serial monitor
    Serial.begin(9600);
    Serial.println("NStim Setup Process Finished");

}

void loop() {
    delay(50);


}