#include "ABuffer.h"
#include <QString>
#include <QDebug>

// Constructor
ABuffer::ABuffer(long frameCount, int sampleRate, QString name) : Buffer(sampleRate, name) {
   qDebug() << "Initializing concrete buffer with name '" << name << "'";
   frames = frameCount;
	data = new double[frameCount];
}

// Destructor
ABuffer::~ABuffer()
{
   qDebug() << "Freeing concrete buffer '" << name << "'";
	delete[] data;
}

inline long ABuffer::getNumberOfSamples() { return frames; }
inline double ABuffer::getSample(long index) { return data[index]; }

//	Copy <frameCount> frames from <source> into the buffer, starting at <startPos>
void ABuffer::copyData(void *source, long startPos, long frameCount)
{
   qDebug() << "Copying data into buffer...";
	try {
		if (startPos + frameCount > frames) throw;
		memcpy(data + startPos*sizeof(double), source, sizeof(double)*frameCount);
	}
	catch (...) {
      qDebug() << "Error: attempted to copy too many frames into a buffer!";
	}
}

