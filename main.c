#include <General_U4C5.h>
#include <Lights_U4C5.h>
#include <Button_U4C5.h>
#include <stdio.h>

#define LIGHTS 3
#define PINS 4

int main(){

    //Estrutura que armazena os pinos e os estados, para facilitar a configuração
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

    //Função que recebe um vetor da estrutura Pin e configura cada pino de acordo com o Input informado, configura também o monitor serial
    Configuration(pins, PINS);
    
    //Configura a interrupção ao pressionar do botão A (gpio 5)
    SetInterruptionButton(pins[3], 3000);

    uint32_t seconds = 0;

    char plural; 

    while(1){
        //Captura o tempo passado em milissegundos e converte para segundos
        seconds = to_ms_since_boot(get_absolute_time()) / 1000;

        //verifica se é tem 0 ou 1s ou vários segundos
        plural = seconds > 1 ? 's' : ' ';

        //Imprime na tela a cada segundo a mensagem Loop do Semáforo e os segundos passados
        printf("%ld segundo%c passado%c -> LEDs + contador One-Shot! - Aplicação funcionando!\n",  seconds, plural, plural);
        sleep_ms(1000);
    }

}