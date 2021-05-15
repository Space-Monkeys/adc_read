#include "adc_read.h"
#include <stdio.h>
#include <stdlib.h>
#include "driver/gpio.h"
#include "driver/adc.h"

#define DEFAULT_VREF 1100 //Use adc2_vref_to_gpio() to obtain a better estimate
#define NO_OF_SAMPLES 64  //Multisampling

#if CONFIG_IDF_TARGET_ESP32
static const adc_channel_t channel = ADC_CHANNEL_7; //GPIO34 if ADC1, GPIO14 if ADC2
static const adc_bits_width_t width = ADC_WIDTH_BIT_12;
#elif CONFIG_IDF_TARGET_ESP32S2
static const adc_channel_t channel = ADC_CHANNEL_7; // GPIO7 if ADC1, GPIO17 if ADC2
static const adc_bits_width_t width = ADC_WIDTH_BIT_13;
#endif
static const adc_atten_t atten = ADC_ATTEN_DB_0;
static const adc_unit_t unit = ADC_UNIT_1;

using namespace std;

int Adc::read(int data)
{
    //Continuously sample ADC1

    uint32_t adc_reading = 0;
    //Multisampling
    for (int i = 0; i < NO_OF_SAMPLES; i++)
    {
        if (unit == ADC_UNIT_1)
        {
            adc_reading += adc1_get_raw((adc1_channel_t)channel);
        }
        else
        {
            int raw;
            adc2_get_raw((adc2_channel_t)channel, width, &raw);
            adc_reading += raw;
        }
    }
    return adc_reading /= NO_OF_SAMPLES;
}