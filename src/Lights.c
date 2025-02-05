#include <Lights_U4C5.h>

//Callback do contador One-Shot
int64_t HandleButtonLED(alarm_id_t id, void *user_data){
    //Verifica o estado de display dos LEDs e ajusta de acordo
    //Primeiro (antes de chamar essa função) com todas as luzes ligadas
    //Primeiro (o primeiro caso) com duas luzes ligadas
    //Depois com uma luz ligada
    //Por fim com todas apagadas
    if(timerContext.TurnedOn == 1){
        gpio_put(BLUE, 1);
        gpio_put(RED, 1);
        gpio_put(GREEN, 0);
        //atualiza o estado no provedor global
        timerContext.TurnedOn++;
        //define novamente um contador com esta função de callback
        add_alarm_in_ms(timerContext.Duration, HandleButtonLED, NULL, false);
    } else if (timerContext.TurnedOn == 2){
        gpio_put(BLUE, 0);
        gpio_put(GREEN, 0);
        gpio_put(RED, 1);
        //atualiza o estado no provedor global   
        timerContext.TurnedOn++;
        //define novamente um contador com esta função de callback
        add_alarm_in_ms(timerContext.Duration, HandleButtonLED, NULL, false);
    } else {
        gpio_put(GREEN, 0);
        gpio_put(RED, 0);
        gpio_put(BLUE, 0);
        //retoma o estado inicial
        timerContext.TurnedOn = 1;
        //habilita que o pressionamento do botão afete os LEDs, pois a sequência terminou
        interruptContext.CanPress = 1;
    }
    //Retorna 0 para não repetir a chamada do callback
    return 0;
}

//Função de teste dos LEDs
void TestLEDs(Pin* pins, uint8_t size, uint32_t duration){
    for(uint8_t i = 0; i < size; i++){
        gpio_put(pins[i].Pin, !gpio_get(pins[i].Pin));
        timerContext.Pins[i] = pins[i];
    }

    timerContext.VectorSize = size;

    add_alarm_in_ms(duration, HandleToggle, NULL, false);

}
// Callback do teste
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
