#pragma once

#include <cstring>
#include <QString>

/*
 *  Buffer: Abstract Base Class
 */
class Buffer
{
	protected:
      // A descriptive name for the buffer
		QString name;

      // Number of samples per second
		int sampleRate;

	public:
      // Constructor
		Buffer(int sampleRate, QString name);

      // Destructor
		virtual ~Buffer();

      // Duration of the buffer in seconds
		double getDuration();

      // The name of the buffer
		const QString& getName();

      // Number of samples in the buffer
      virtual long getNumberOfSamples() = 0;

      // Get the value at a specific point in the buffer
      virtual double getSample(long index) = 0;
};

