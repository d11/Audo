#ifndef _STANDARDBUFFER_H_
#define _STANDARDBUFFER_H_

#include "Buffer.h"
#include <QString>

class StandardBuffer : public Buffer {
	public:
		StandardBuffer(long frameCount, int sampleRate);
		~StandardBuffer();
      long getNumberOfSamples();
      double getSample(long index);
      void copyData(void *source, long startPos, long frameCount);

	protected:
		long frames;
      double *data;
};
#endif /* _STANDARDBUFFER_H_ */
