#include <Arduino.h>
// #include <EEPROM.h>
// #include <Wire.h>
// #include <UnicViewAD.h>
// #include <Fsm.h>

#include "iopins.h"
#include "button.h"
// #include "config.h"

// // Slave Unit (2nd Arduino) I2C Address
// #define SLAVE_UNIT_ADDRESS  1


// // Init Proculus display
// LCM Lcm(Serial);

// control variables
int counter = 0;
int currentState_ROTARY_CLK;
int previousState_ROTARY_CLK;
String encdir = "";


Button *btnStart = new Button(BTN_START);       // GREEN BUTTON
Button *btnStop = new Button(BTN_STOP);         // RED BUTTON
Button *btnPower = new Button(BTN_ONOFF);       // BLUE BUTTON
Button *btnEncoder = new Button(BTN_ENCODER);   // ENCODER BUTTON


void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(INPUT_ROTARY_CLK, INPUT);
  pinMode(INPUT_ROTARY_DAT, INPUT);


    // NStimConfig *nstim = setupConfig();

    // setup display
    // Lcm.begin();  // Inicia e configura o LCM

    // setup I2C
    // Wire.begin();

    // setup Encoder Pins
    // pinMode (INPUT_ROTARY_CLK, INPUT);
    // pinMode (INPUT_ROTARY_DAT, INPUT);




    // Read the initial state of INPUT_ROTARY_CLK
    previousState_ROTARY_CLK = digitalRead(INPUT_ROTARY_CLK);

    // setup serial monitor
    Serial.begin(115200);
    Serial.println("NStim Setup Process Finished");

  analogWrite(LED_R, 125);
  analogWrite(LED_G, 125);
  analogWrite(LED_B, 125);
  digitalWrite(LED_8, 1);
  digitalWrite(LED_7, 1);
  digitalWrite(LED_6, 1);
  digitalWrite(LED_5, 1);
  digitalWrite(LED_4, 1);
  digitalWrite(LED_3, 1);

}

void loop() {
    // delay(10);

    btnStart->loop();
    btnStop->loop();
    btnPower->loop();
    btnEncoder->loop();


    // ROTARY ENCODER
    // currentState_ROTARY_CLK = analogRead(INPUT_ROTARY_CLK);
    // Serial.println(currentState_ROTARY_CLK);
    // if (currentState_ROTARY_CLK != previousState_ROTARY_CLK) {
    //     if (digitalRead(INPUT_ROTARY_DAT) != currentState_ROTARY_CLK) {
    //         // rotating counterclockwise
    //         counter --;
    //         encdir = "CCW";
    //     } else {
    //         // rotating clockwise
    //         counter ++;
    //         encdir = "CW";
    //     }
    //     Serial.println(encdir);
    //     Serial.println(counter);
    // }
    // previousState_ROTARY_CLK = currentState_ROTARY_CLK;


}