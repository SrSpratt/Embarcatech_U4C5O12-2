#include <General_U4C5.h>

Context context;

void Configuration(Pin* pins, uint8_t size){
    stdio_init_all();

    for (uint8_t i = 0; i < size; i++){
        if (pins[i].Input)
            SetInput(pins[i].Pin);
        else
            SetOutput(pins[i].Pin);
    }
}

void SetInput(uint8_t pin){
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_down(pin);
}

void SetOutput(uint8_t pin){
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, 0);
}

void PrintPin(Pin pin){
    printf("Pin ====\n");
    printf("Pin: %d\n", pin.Pin);
    printf("Input?: %d\n", pin.Input);
    printf("\n");
}

void PrintContext(Context context){
    printf("Context ====\n");
    printf("Vector: %d\n", context.VectorSize);
    printf("LastState: %d\n", context.TurnedOn);
    for (uint8_t i = 0; i < context.VectorSize; i++){
        PrintPin(context.Pins[i]);
    }
    
}
