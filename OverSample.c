#include <stdint.h>
#include "OverSample.h"

uint16_t OverSamplePoints = 0;
uint32_t OversamplePresentValue = 0;

int DSP_OverSample_Config(const uint8_t ADCbits, const uint8_t DesiredBits)
{
	if(ADCbits <= DesiredBits)
	{
		return -1;
	}
	else
	{
		switch(ADCbits - DesiredBits)
		{
			case 1: OverSamplePoints = ADD1BIT; break;
			case 2: OverSamplePoints = ADD2BITS; break;
			case 3: OverSamplePoints = ADD3BITS; break;
			case 4: OverSamplePoints = ADD4BITS; break;
			case 5: OverSamplePoints = ADD5BITS; break;
			case 6: OverSamplePoints = ADD6BITS; break;
			case 7: OverSamplePoints = ADD7BITS; break;
			case 8: OverSamplePoints = ADD8BITS; break;
			default: return -1;			
		}
	}
	return 0;	
}

void DSP_OverSample_ISRCall(const uint32 ADCValue)
{
	static uint16_t PointCounter = OverSamplePoints;
	static uint32_t PresentValueAccumulator = 0;
	
	PresentValueAccumulator += (ADCValue / OverSamplePoints);
	if(--PointCounter == 0)
	{
		PointCounter = OverSamplePoints;
		OverSamplePresentValue = PresentValueAccumulator;
		PresentValueAccumulator = 0;
	}
}

uint32_t DSP_OverSample_GetCurrentValue(void)
{
	return OverSamplePresentValue;
}
