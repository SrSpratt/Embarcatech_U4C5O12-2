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
    if(timerContext.TurnedOn == BLUE){
        gpio_put(BLUE, 0);
        gpio_put(RED, 0);
        gpio_put(GREEN, 1);
        timerContext.TurnedOn = GREEN;
    } else if (timerContext.TurnedOn == GREEN){
        gpio_put(BLUE, 0);
        gpio_put(GREEN, 0);
        gpio_put(RED, 1);   
        timerContext.TurnedOn = RED;
    } else {
        gpio_put(GREEN, 0);
        gpio_put(RED, 0);
        gpio_put(BLUE, 1);
        timerContext.TurnedOn = BLUE;
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
    if(timerContext.TurnedOn == BLUE){
        gpio_put(BLUE, 0);
        gpio_put(RED, 0);
        gpio_put(GREEN, 1);
        timerContext.TurnedOn = GREEN;
    } else if (timerContext.TurnedOn == GREEN){
        gpio_put(BLUE, 0);
        gpio_put(GREEN, 0);
        gpio_put(RED, 1);   
        timerContext.TurnedOn = RED;
    } else {
        gpio_put(GREEN, 0);
        gpio_put(RED, 0);
        gpio_put(BLUE, 1);
        timerContext.TurnedOn = BLUE;
    }
    return timerContext.Duration;
}

int64_t HandleButtonLED(alarm_id_t id, void *user_data){
    //PrintContext(timerContext);
    if(timerContext.TurnedOn == 1){
        gpio_put(BLUE, 1);
        gpio_put(RED, 1);
        gpio_put(GREEN, 0);
        timerContext.TurnedOn++;
        add_alarm_in_ms(timerContext.Duration, HandleButtonLED, NULL, false);
    } else if (timerContext.TurnedOn == 2){
        gpio_put(BLUE, 0);
        gpio_put(GREEN, 0);
        gpio_put(RED, 1);   
        timerContext.TurnedOn++;
        add_alarm_in_ms(timerContext.Duration, HandleButtonLED, NULL, false);
    } else {
        gpio_put(GREEN, 0);
        gpio_put(RED, 0);
        gpio_put(BLUE, 0);
        timerContext.TurnedOn = 1;
        interruptContext.CanPress = 1;
    }
    return 0;
}