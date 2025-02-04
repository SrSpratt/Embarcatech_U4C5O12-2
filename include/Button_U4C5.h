#ifndef BUTTON_U4C5_H
#define BUTTON_U4C5_H

#define BUTTON 5

#include <General_U4C5.h>

void TestButton(Pin);
void SetInterruptionButton(Pin pin, uint32_t duration);
void HandleInterrupt();


#endif