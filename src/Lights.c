#include <Lights_U4C5.h>

RepeatingTimer repeatingTimer;
void FireInOrder(Pin* pins, uint8_t size, uint32_t duration, uint8_t first){
    timerContext.VectorSize = size;
    
    gpio_put(pins[first].Pin, 1);
    timerContext.TurnedOn = pins[first].Pin;
    
    add_repeating_timer_ms(duration, HandleChangeLED, NULL, &repeatingTimer);
    //add_alarm_in_ms(duration, HandleChangeLED, NULL, false);
}

bool HandleChangeLED(RepeatingTimer *t){
    //printf("context turned on: %d\n", context.TurnedOn);
    if(timerContext.TurnedOn == REDLIGHT){
        gpio_put(REDLIGHT, 0);
        gpio_put(GREENLIGHT, 0);
        gpio_put(YELLOWLIGHT, 1);
        timerContext.TurnedOn = YELLOWLIGHT;
    } else if (timerContext.TurnedOn == YELLOWLIGHT){
        gpio_put(REDLIGHT, 0);
        gpio_put(YELLOWLIGHT, 0);
        gpio_put(GREENLIGHT, 1);   
        timerContext.TurnedOn = GREENLIGHT;
    } else {
        gpio_put(YELLOWLIGHT, 0);
        gpio_put(GREENLIGHT, 0);
        gpio_put(REDLIGHT, 1);
        timerContext.TurnedOn = REDLIGHT;
    }

    return true;
}


void TestLEDs(Pin* pins, uint8_t size, uint32_t duration){
    for(uint8_t i = 0; i < size; i++){
        gpio_put(pins[i].Pin, !gpio_get(pins[i].Pin));
        //PrintPin(pins[i]);
        timerContext.Pins[i] = pins[i];
    }

    //sleep_ms(duration);
    timerContext.VectorSize = size;
    //PrintContext(context);
    add_alarm_in_ms(duration, HandleToggle, NULL, false);

    // for(uint8_t i = 0; i < size; i++)
    //     gpio_put(pins[i].Pin, !gpio_get(pins[i].Pin));
}

int64_t HandleToggle(alarm_id_t id, void *user_data){
    PrintContext(timerContext);
    for(uint8_t i = 0; i < timerContext.VectorSize; i++){
        gpio_put(timerContext.Pins[i].Pin, !gpio_get(timerContext.Pins[i].Pin));
        //PrintPin(context.Pins[i]);
    }
    return 0;
}