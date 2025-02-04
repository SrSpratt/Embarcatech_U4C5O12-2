#ifndef GENERAL_U4C5_H
#define GENERAL_U4C5_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

/**
 * @brief Representa um pino e sua configuração de entrada ou saída.
 */
typedef struct PinOut {
    uint8_t Pin;  // Número do pino 
    bool Input;   // Entrada? -> entrada se for verdadeiro e saída se não for.
} Pin;

/**
 * @brief Armazena o contexto do temporizador.
 */
typedef struct TimerContext {
    uint8_t TurnedOn; // Vai ser usado para armazenar o pino ligado na chamada do temporizador 
    uint8_t VectorSize;
    Pin Pins[3];
} Context;

/**
 * @brief Contexto global do temporizador, para armazenar o estado anterior à chamada do callback.
 */
extern Context context;

/**
 * @brief Configura pinos como entrada ou saída.
 *
 * @param pins Ponteiro para um vetor de `Pins`, com as configurações dos pinos.
 * @param size Quantidade de pinos.
 */
void Configuration(Pin* pins, uint8_t size);

/**
 * @brief Configura um pino como entrada.
 *
 * @param pin Número do pino.
 */
void SetInput(uint8_t pin);

/**
 * @brief Configura um pino como saída.
 *
 * @param pin Número do pino.
 */
void SetOutput(uint8_t pin);

void PrintPin(Pin pin);
void PrintContext(Context context);

/**
 * @brief Callback do temporizador (ainda vou implementar).
 */
void TimerCallback();

#endif 
