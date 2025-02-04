#include <General_U4C5.h>
#include <Lights_U4C5.h>
#include <Button_U4C5.h>
#include <stdio.h>

#define LIGHTS 3
#define PINS 4

int main(){

    Pin pins[PINS] = {
        {
            .Pin = REDLIGHT,
            .Input = false
        },
        {
            .Pin = YELLOWLIGHT,
            .Input = false
        },
        {
            .Pin = GREENLIGHT,
            .Input = false
        },
        {
            .Pin = BUTTON,
            .Input = true
        }
    };

    Configuration(pins, PINS);
    
    TestButton(pins[3]);
    //PrintPin(pins[1]);
    //add_alarm_in_ms(100, HandleToggle, NULL, true);
    //TestLEDs(pins, LIGHTS, 500);
    FireInOrder(pins, LIGHTS, 3000, 0);
    uint8_t state;
}