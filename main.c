#include <General_U4C5.h>
#include <Lights_U4C5.h>
#include <Button_U4C5.h>
#include <stdio.h>

#define LIGHTS 3
#define PINS 4

int main(){

    Pin pins[PINS] = {
        {
            .Pin = BLUE,
            .Input = false
        },
        {
            .Pin = RED,
            .Input = false
        },
        {
            .Pin = GREEN,
            .Input = false
        },
        {
            .Pin = BUTTON,
            .Input = true
        }
    };

    Configuration(pins, PINS);
    
    SetInterruptionButton(pins[3], 500);

    //TestButton(pins[3]);
    //PrintPin(pins[1]);
    //TestLEDs(pins, LIGHTS, 500);

}