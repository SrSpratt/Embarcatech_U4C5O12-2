#ifndef LIGHTS_U4C5_H
#define LIGHTS_U4C5_H

#include <General_U4C5.h>  // Inclui as definições gerais dos pinos e funções

/**
 * @brief Definições dos pinos dos LEDs de sinalização.
 */
#define BLUE 11      // Pino do LED vermelho 
#define RED 12   // Pino do LED amarelo 
#define GREEN 13    // Pino do LED verde 


/**
 * @brief Testa os LEDs invertendo seu estado por um curto período de tempo.
 *
 * @param pins Ponteiro para um vetor de `PinState`, que contém os pinos e seus estados atuais.
 * @param size Quantidade de pinos.
 * @param duration Duração do teste em milissegundos.
 */
void TestLEDs(Pin* pins, uint8_t size, uint32_t duration);

int64_t HandleToggle(alarm_id_t id, void *user_data);

int64_t HandleButtonLED(alarm_id_t id, void *user_data);

#endif /* LIGHTS_U4C5_H */
