#include <Arduino.h>
#include "button.h"

Button::Button(int btnPin, unsigned long debounceDelay = DEFAULT_DELAY)
{
    pin = btnPin;
    lastDebounceTime = 0;
    lastState = HIGH;
    state = HIGH;
    delay = debounceDelay;
    pinMode(pin, INPUT);
}

// Button::~Button() {}

void Button::loop()
{
    char saida[40];
    int reading = digitalRead(pin);

    if (reading != lastState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > delay)
    {
        if (reading != state)
        {
            state = reading;
            sprintf(saida, "Button at %d: | State: %d", pin, state);
            Serial.println(saida);
        }
    }

    lastState = reading;
}