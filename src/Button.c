#include <Button_U4C5.h>

void TestButton(Pin pin){
    PrintPin(pin);
    uint8_t state = gpio_get(pin.Pin);
    printf("BOTÃO EM NÍVEL LÓGICO BAIXO\n");
    while(state != 1){
        state = gpio_get(pin.Pin);
        //printf("Att, entrada: %d\n", state);
    }
    printf("BOTÃO APERTADO\n");
}