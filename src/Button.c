#include <Button_U4C5.h>
#include <Lights_U4C5.h>

InterruptContext interruptContext = {
    .CanPress = 1,
    .DebounceBuffer = 0
};

void TestButton(Pin pin){
    PrintPin(pin);
    uint8_t state = gpio_get(pin.Pin);
    printf("BOTÃO EM NÍVEL LÓGICO BAIXO\n");
    while(state != 1){
        state = gpio_get(pin.Pin);
    }
    printf("BOTÃO APERTADO\n");
}

void SetInterruptionButton(Pin pin, uint32_t duration){
    timerContext.Duration = duration;
    timerContext.Pins[0] = pin;
    gpio_set_irq_enabled_with_callback(pin.Pin, GPIO_IRQ_EDGE_RISE, true, HandleInterrupt);
}

void HandleInterrupt(){
    uint32_t currentTime = to_ms_since_boot(get_absolute_time());

    if (currentTime - interruptContext.DebounceBuffer > 200){
        if (interruptContext.CanPress == 1){
            interruptContext.CanPress = 0;
            timerContext.TurnedOn = 1;
            gpio_put(GREEN, 1);
            gpio_put(RED, 1);
            gpio_put(BLUE, 1);
            add_alarm_in_ms(timerContext.Duration, HandleButtonLED, NULL, false);
        } else {
            if (gpio_get(timerContext.Pins[0].Pin) == 1)
                printf("NÃO CAPTURA O ESTADO DURANTE A SEQUÊNCIA\n");
        }
        interruptContext.DebounceBuffer = currentTime;
    }
}