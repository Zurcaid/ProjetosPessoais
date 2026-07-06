#include "arduinoFFT.h"

/*
These values can be changed in order to evaluate the functions
*/
#define CHANNEL A0
#define led 8
const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const float samplingFrequency = 200; //Hz, must be less than 10000 due to ADC
unsigned int sampling_period_us;
unsigned long microseconds;

/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
float vReal[samples];
float vImag[samples];

/* Create FFT object with weighing factor storage */
ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, samples, samplingFrequency, true);

#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

int count = 0;
float med = 0;

void setup()
{
  pinMode(led, OUTPUT);
  sampling_period_us = round(1000000*(1.0/samplingFrequency));
  Serial.begin(115200);
  Serial.println("Ready");
}

void loop()
{
  /*SAMPLING*/
  microseconds = micros();
  for(int i=0; i<samples; i++)
  {
      vReal[i] = analogRead(CHANNEL);
      vImag[i] = 0;
      while(micros() - microseconds < sampling_period_us){
        //empty loop
      }
      microseconds += sampling_period_us;
  }
  /* Print the results of the sampling according to time */
  FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);  /* Weigh data */
  FFT.compute(FFTDirection::Forward); /* Compute FFT */
  FFT.complexToMagnitude(); /* Compute magnitudes */
  
//  Serial.println("Computed magnitudes:");
  PrintVector(vReal, (samples >> 1), SCL_FREQUENCY);  
  
//  float x = FFT.majorPeak();
//  Serial.println(x); //Print out what frequency is the most dominant.
  
//   delay(200); /* Repeat after delay */
//  while(1);/
}

void PrintVector(float *vData, uint16_t bufferSize, uint8_t scaleType)
{
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    float abscissa;
    /* Print abscissa value */
    switch (scaleType)
    {
      case SCL_INDEX:
        abscissa = (i * 1.0);
  break;
      case SCL_TIME:
        abscissa = ((i * 1.0) / samplingFrequency);
  break;
      case SCL_FREQUENCY:
        abscissa = ((i * 1.0 * samplingFrequency) / samples);
  break;
    }

    // 0Hz - 0; 3Hz - 1; 6hz - 2; 10Hz - 3; 13hz - 4; 15Hz - 5; 19Hz - 6; 21Hz - 7; 25Hz - 8; 28Hz - 9; 31Hz - 10; On sample frequency of 200
    // Value = Amplitude*1500
//    Serial.print(abscissa);
//    if(scaleType==SCL_FREQUENCY)
//      Serial.print("Hz");
//      Serial.print(i);
//    Serial.print(" ");
    if(i == 3){
      if(count > 4){
        Serial.println(med/5);
        if((med/5) > 0.8){
          digitalWrite(led, HIGH);
        }else{
          digitalWrite(led, LOW);
        }
        count = 0;
        med = 0;
      }     
      med += vData[3]/1500;
      count += 1;
    }
//    Serial.println(vData[3]/1500);
  }
  // Serial.println();
}
