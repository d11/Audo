#pragma once

#include "Buffer.h"
#include <QString>

class EmptyBuffer : public Buffer {
	public:
		EmptyBuffer(long frameCount, int sampleRate);
		~EmptyBuffer();
      long getNumberOfSamples();
      double getSample(long index);

	protected:
		long frames;
};

