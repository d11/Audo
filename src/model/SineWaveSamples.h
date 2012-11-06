#pragma once

#include "SampleSource.h"
#include "SampleInterval.h"
#include <cmath>

class SineWaveSamples : public SampleSource
{
public:
   SineWaveSamples(float frequency, float phase) : m_frequency(frequency), m_phase(phase) { }
   virtual ~SineWaveSamples() { }

   virtual void getSamples(const SampleInterval & interval, const WritableBufferRef & outputBuffer)
   {
      t_audoNSamples sample = interval.getStart();

      std::cout << "Filling buffer with data for samples " << sample << " - " << interval.getEnd() << std::endl;

      float *data = outputBuffer->getDataPointer();
      while (sample < interval.getEnd())
      {
         *data = std::sin((sample / 44100.0f * m_frequency + m_phase) * M_PI * 2.0f);
         ++data;
         ++sample;
      }
   }

private:
   float m_frequency;
   float m_phase;

};
