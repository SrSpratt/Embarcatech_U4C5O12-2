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
    uint8_t Pin;  // Número do pino.
    bool Input;   // Define se o pino é de entrada (true) ou saída (false).
} Pin;

/**
 * @brief Armazena o contexto do temporizador, incluindo o estado dos pinos e a duração do evento temporizado.
 */
typedef struct TimerContext {
    uint8_t TurnedOn;      ///< Pino atualmente ligado no temporizador.
    uint8_t VectorSize;    ///< Número total de pinos armazenados no contexto.
    Pin Pins[3];           ///< Vetor contendo os pinos controlados pelo temporizador.
    uint32_t Duration;     ///< Duração do evento temporizado em milissegundos.
} TimerContext;

/**
 * @brief Estrutura que armazena informações de interrupções, como debounce e permissões.
 */
typedef struct InterruptContext {
    bool CanPress;         // Indica se o botão pode ser pressionado (controle do botão durante a sequência).
    uint32_t DebounceBuffer; // Buffer para controle do tempo de debounce (controle de debounce).
    uint8_t Duration;      // Duração da interrupção em milissegundos.
} InterruptContext;

/**
 * @brief Contexto global do temporizador, para armazenar o estado anterior à chamada do callback.
 */
extern TimerContext timerContext;
extern InterruptContext interruptContext;

/**
 * @brief Configura um conjunto de pinos como entrada ou saída, inicializando-os adequadamente.
 *
 * @param Pin* Ponteiro para um vetor de pinos a serem configurados.
 * @param uint8_t Quantidade de pinos no vetor.
 */
void Configuration(Pin*, uint8_t);

/**
 * @brief Configura um pino específico como entrada, ativando o pull-down.
 *
 * @param uint8_t Número do pino a ser configurado como entrada.
 */
void SetInput(uint8_t);

/**
 * @brief Configura um pino específico como saída e o inicializa em nível lógico baixo.
 *
 * @param uint8_t Número do pino a ser configurado como saída.
 */
void SetOutput(uint8_t);

/**
 * @brief Imprime no console as informações de um pino.
 *
 * @param Pin Estrutura representando o pino a ser impresso.
 */
void PrintPin(Pin);

/**
 * @brief Exibe no console o estado atual do contexto do temporizador, incluindo os pinos armazenados.
 *
 * @param TimerContext Estrutura contendo o contexto atual do temporizador.
 */
void PrintContext(TimerContext);

#endif 
