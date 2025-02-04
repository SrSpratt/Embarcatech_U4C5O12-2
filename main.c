#include <General_U4C5.h>
#include <Lights_U4C5.h>
#include <stdio.h>

#define LIGHTS 3

int main(){

    Pin pins[LIGHTS] = {
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

    };

    Configuration(pins, LIGHTS);
    
    //PrintPin(pins[1]);
    //add_alarm_in_ms(100, HandleToggle, NULL, true);
    //TestLEDs(pins, LIGHTS, 500);
    FireInOrder(pins, LIGHTS, 3000, 0);
}