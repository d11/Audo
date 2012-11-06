#pragma once

#include <cstring>
#include <QString>
#include "util/AudoTypes.h"

/*
 *  Buffer: Abstract Base Class
 */
class Buffer
{
public:
   // Constructor
   Buffer(t_audoNSamples sampleRate, const QString & name);

   // Destructor
   virtual ~Buffer();

   // Duration of the buffer in seconds
   double getDuration() const;

   // The name of the buffer
   const QString& getName() const;

   // Get number of samples per second
   virtual t_audoNSamples getSampleRate() const;

   // Number of samples in the buffer
   virtual t_audoNSamples getNumberOfSamples() const = 0;

   // Get the value at a specific point in the buffer
   virtual double getSample(t_audoNSamples index) const = 0;

private:

   // A descriptive name for the buffer
   QString m_name;

   // Number of samples per second
   t_audoNSamples m_sampleRate;
};

