#include <Button_U4C5.h>
#include <Lights_U4C5.h>

//Provedor global da interrupção
InterruptContext interruptContext = {
    .CanPress = 1,
    .DebounceBuffer = 0
};

//módulo de teste do botão
void TestButton(Pin pin){
    PrintPin(pin);
    uint8_t state = gpio_get(pin.Pin);
    printf("BOTÃO EM NÍVEL LÓGICO BAIXO\n");
    while(state != 0){
        state = gpio_get(pin.Pin);
    }
    printf("BOTÃO APERTADO\n");
}

//Configura a interrupção para o botão da gpio5
void SetInterruptionButton(Pin pin, uint32_t duration){
    //salva a duração dos contadores no provedor global do contador
    timerContext.Duration = duration;
    //salva o pino do botão no provedor global do contador
    timerContext.Pins[0] = pin;
    //configura a interrupção e define que a função de callback será HandleInterrupt
    gpio_set_irq_enabled_with_callback(pin.Pin, GPIO_IRQ_EDGE_FALL, true, HandleInterrupt);
}

void HandleInterrupt(){
    //pega o tempo desde o início da execução
    uint32_t currentTime = to_ms_since_boot(get_absolute_time());

    //implementação do debounce nesse condicional
    if (currentTime - interruptContext.DebounceBuffer > 300){
        //Verifica se o pressionamento do botão está habilitado (canpress)
        if (interruptContext.CanPress == 1){
            printf("\t *INTERRUPÇÃO -> INICIAR SEQUÊNCIA* \n");

            // Define o canpress como 0, desabilitando a interferência do pressionamento do botão até a sequência iniciada agora terminar
            interruptContext.CanPress = 0;
            // Salva o estado de display dos LEDs no provedor global de contador
            timerContext.TurnedOn = 1;

            //Modifica o display inicial
            gpio_put(GREEN, 1);
            gpio_put(RED, 1);
            gpio_put(BLUE, 1);

            //Define o contador para a duração duration
            add_alarm_in_ms(timerContext.Duration, HandleButtonLED, NULL, false);
        } else {
            //Avisa que o pressionamento não interfere durante a sequência dos LEDs
            if (gpio_get(timerContext.Pins[0].Pin) == 0)
                printf("\t *INTERRUPÇÃO -> NÃO CAPTURA O ESTADO DURANTE A SEQUÊNCIA* \n");
        }

        //Atualiza o tempo do buffer de debounce
        interruptContext.DebounceBuffer = currentTime;
    }
}