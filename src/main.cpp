#include <Arduino.h>
#include <SoftwareSerial.h>
#include <UnicViewAD.h>

// #include <EEPROM.h>
// #include <Wire.h>
#include <Fsm.h>

#include "iopins.h"
#include "button.h"
// #include "config.h"

SoftwareSerial softSerial(SOFT_RX, SOFT_TX); // RX, TX

// // // Slave Unit (2nd Arduino) I2C Address
// // #define SLAVE_UNIT_ADDRESS  1

// // Init Proculus display
LCM Lcm(softSerial);

Button *btnStart = new Button(BTN_START);     // GREEN BUTTON
Button *btnStop = new Button(BTN_STOP);       // RED BUTTON
Button *btnPower = new Button(BTN_ONOFF);     // BLUE BUTTON
Button *btnEncoder = new Button(BTN_ENCODER); // ENCODER BUTTON

const int ledOn = 1;             // Valor para ligar o LED
const int ledOff = 0;            // Valor para desligar o LED
LcmVar ledButton(16);            // Cria um objeto com o nome de ledButton configurado com o VP 16


// // Transition callback functions
// void on_light_on_enter()
// {
//   Serial.println("Entering LIGHT_ON");
// }

// void on_light_on_exit()
// {
//   Serial.println("Exiting LIGHT_ON");
// }

// void on_light_off_enter()
// {
//   Serial.println("Entering LIGHT_OFF");
// }

// void on_light_off_exit()
// {
//   Serial.println("Exiting LIGHT_OFF");
// }

// void on_trans_light_on_light_off()
// {
//   Serial.println("Transitioning from LIGHT_ON to LIGHT_OFF");
// }

// void on_trans_light_off_light_on()
// {
//   Serial.println("Transitioning from LIGHT_OFF to LIGHT_ON");
// }


// #define FLIP_LIGHT_SWITCH 1
// Fsm fsm;
// State state_light_on(on_light_on_enter, &on_light_on_exit);
// State state_light_off(on_light_off_enter, &on_light_off_exit);

void turnOnLed() {
    digitalWrite(LED_3, LOW);
}

void turnOffLed() {
    digitalWrite(LED_3, HIGH);
}


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

  analogWrite(LED_R, 125);
  analogWrite(LED_G, 125);
  analogWrite(LED_B, 125);
  digitalWrite(LED_8, HIGH);
  digitalWrite(LED_7, HIGH);
  digitalWrite(LED_6, HIGH);
  digitalWrite(LED_5, HIGH);
  digitalWrite(LED_4, HIGH);
  digitalWrite(LED_3, HIGH);

  Serial.begin(115200);
  softSerial.begin(115200);
  Lcm.begin();
  delay(3000);

  // char saida[40];
  // int version = Lcm.readFirmwareVersion();
  // sprintf(saida, "LCM Firmware version: %d", version);


  // setup serial monitor
  Serial.println("NStim Setup Process Finished");
  // Serial.println(saida);

  // int version = Lcm.readFirmwareVersion();
  // delay(1000);
  // Serial.println(version);

  // Lcm.changeBacklight(50);
  // delay(1000);

  // Lcm.changePicId(0);
  // delay(1000);

  // delay(2000);
  // Lcm.changeBacklight(10);
  // Lcm.changePicId(0);

  // Serial.println("LCM Set");
  // setup I2C
  // Wire.begin();

    // fsm.add_transition(&state_light_on, &state_light_off,FLIP_LIGHT_SWITCH,&on_trans_light_on_light_off);
    // fsm.add_transition(&state_light_off, &state_light_on,FLIP_LIGHT_SWITCH,&on_trans_light_off_light_on);

    btnStart->setAction(turnOnLed);
    btnStop->setAction(turnOffLed);
}


void loop() {
  // delay(10);

  btnStart->loop();
  btnStop->loop();
  btnPower->loop();
  btnEncoder->loop();

  // int picId = Lcm.readPicId();



// *******************************************************************************************************************************************
// * Seleção do tipo de controle do servo
// *******************************************************************************************************************************************
  if (ledButton.available()) {              // Verifica se chegou algo no objeto ledButton
    Serial.println("ledButton available");
    // Serial.println("picId" + picId);
    int LED_estado = ledButton.getData();   // Verifica se o valor recebido pelo
    Serial.println("got data");
    if (LED_estado == ledOn) {              // "ledButton" é igual a ledOn
      Serial.println("turn on led...");
      digitalWrite(LED_3, LOW);             // Liga o LED
      // Lcm.changePicId(0);
      // delay(1000);
    }
    if (LED_estado == ledOff) {              // Verifica se o valor recebido pelo "ledButton" é igual a "ledOff"
      Serial.println("turn off led...");    
      digitalWrite(LED_3, HIGH);         // Desliga o LED
      // Lcm.calibrate();
      // delay(1000);
    }
  }
}