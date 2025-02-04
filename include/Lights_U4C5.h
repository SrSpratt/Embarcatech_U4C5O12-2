#ifndef LIGHTS_U4C5_H
#define LIGHTS_U4C5_H

#include <General_U4C5.h>  // Inclui as definições gerais dos pinos e funções

/**
 * @brief Definições dos pinos dos LEDs de sinalização.
 */
#define BLUE 11      // Pino do LED azul 
#define RED 12       // Pino do LED vermelho 
#define GREEN 13     // Pino do LED verde 

/**
 * @brief Testa os LEDs invertendo seu estado por um curto período de tempo.
 *
 * @param Pin* Ponteiro para um vetor de pinos.
 * @param uint8_t Quantidade de pinos.
 * @param uint32_t Duração do teste em milissegundos.
 */
void TestLEDs(Pin*, uint8_t, uint32_t);

/**
 * @brief Manipula a inversão dos LEDs após o tempo determinado.
 *
 * @param alarm_id_t Identificador do alarme.
 * @param void* Dados adicionais (não utilizados).
 * @return int64_t Retorna o tempo para o próximo alarme ou 0 caso não se repita.
 */
int64_t HandleToggle(alarm_id_t, void*);

/**
 * @brief Manipula a alternância do LED ao pressionar um botão.
 *
 * @param alarm_id_t Identificador do alarme.
 * @param void* Dados adicionais (não utilizados).
 * @return int64_t Retorna o tempo para o próximo alarme ou 0 caso não se repita.
 */
int64_t HandleButtonLED(alarm_id_t, void*);

#endif 
