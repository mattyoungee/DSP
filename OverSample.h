#ifndef OVERSAMPLE_H
#define OVERSAMPLE_H

#define ADD1BIT 3
#define ADD2BITS 15
#define ADD3BITS 63
#define ADD4BITS 255
#define ADD5BITS 1023
#define ADD6BITS 4095
#define ADD7BITS 16383
#define ADD8BITS 65535

int DSP_OverSample_Config(const uint8_t ADCbits, const uint8_t DesiredBits);
void DSP_OverSample_ISRCall(const uint32 ADCValue);
uint32_t DSP_Oversample_GetCurrentValue(void);

#endif
