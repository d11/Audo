#pragma once

#include "Buffer.h"
#include <QString>

class StandardBuffer : public Buffer {
	public:
		StandardBuffer(long frameCount, int sampleRate, QString name);
      StandardBuffer(long frameCount, int sampleRate, QString name, float *data);
		~StandardBuffer();
      long getNumberOfSamples();
      double getSample(long index);
      void copyData(void *source, long startPos, long frameCount);

	protected:
		long mFrames;
      float *mData;
      bool m_owned;
};
