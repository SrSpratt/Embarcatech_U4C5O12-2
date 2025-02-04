#include <Lights_U4C5.h>

void TestLEDs(Pin* pins, uint8_t size, uint32_t duration){
    for(uint8_t i = 0; i < size; i++){
        gpio_put(pins[i].Pin, !gpio_get(pins[i].Pin));
        timerContext.Pins[i] = pins[i];
    }

    timerContext.VectorSize = size;

    add_alarm_in_ms(duration, HandleToggle, NULL, false);

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