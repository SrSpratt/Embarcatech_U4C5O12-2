#ifndef BUTTON_U4C5_H
#define BUTTON_U4C5_H

#define BUTTON 5  ///< Define o pino onde o botão está conectado.

#include <General_U4C5.h>

/**
 * @brief Testa o funcionamento do botão, exibindo mensagens conforme seu estado.
 *
 * @param Pin Estrutura representando o botão a ser testado.
 */
void TestButton(Pin);

/**
 * @brief Configura uma interrupção para detectar quando o botão é pressionado.
 *
 * @param Pin Estrutura representando o botão que terá a interrupção configurada.
 * @param uint32_t Tempo de debounce para evitar múltiplas detecções indesejadas (em milissegundos).
 */
void SetInterruptionButton(Pin, uint32_t);

/**
 * @brief Manipulador da interrupção gerada pelo botão, acionando os LEDs e aplicando debounce.
 */
void HandleInterrupt();

#endif 
