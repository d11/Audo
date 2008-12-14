#ifndef _ABUFFER_H_
#define _ABUFFER_H_

#include "Buffer.h"
#include <QString>

class ABuffer : public Buffer {
	public:
		ABuffer(long frameCount, int sampleRate, QString name);
		~ABuffer();
      long getNumberOfSamples();
      double getSample(long index);
      void copyData(void *source, long startPos, long frameCount);

	protected:
		long frames;
      double *data;
};
#endif /* _ABUFFER_H_ */
