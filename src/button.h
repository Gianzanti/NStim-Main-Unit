/**
 * Author: Fabio Gianzanti (pardal@hotmail.com)
 * Revisor:
 *
 * Button class to deal with debounce and button state
 *
 */

#ifndef __BUTTON_H_
#define __BUTTON_H_

#define DEFAULT_DELAY 30

class Button
{
private:
    unsigned long lastDebounceTime;
    int state;
    int lastState;
    int pin;
    unsigned long delay;

public:
    Button(int pin, unsigned long debounceDelay = DEFAULT_DELAY);
    // ~Button();
    void loop();
};

#endif