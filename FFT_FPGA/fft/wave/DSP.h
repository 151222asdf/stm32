#ifndef __DSP_H__
#define __DSP_H__
#include <stdbool.h>
#include <stdint.h>

//void PowerPhaseRadians_f32(uint16_t _usFFTPoints, float _uiCmpValue);
 void cfft_f32_mag(void);
// void cfft_f32_phase(void);
 void delay_ms(int ms);
 void delay_10us(int us);
#endif
