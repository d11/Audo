#include "StandardBuffer.h"
#include <QString>
#include <QDebug>

// Constructor
StandardBuffer::StandardBuffer(long frameCount, int sampleRate, QString name) : Buffer(sampleRate, name) {
   qDebug() << "Initializing concrete buffer with name '" << name << "'";
   frames = frameCount;
	data = new double[frameCount];
}

// Destructor
StandardBuffer::~StandardBuffer()
{
   qDebug() << "Freeing concrete buffer '" << name << "'";
	delete[] data;
}

inline long StandardBuffer::getNumberOfSamples() { return frames; }
inline double StandardBuffer::getSample(long index) { return data[index]; }

//	Copy <frameCount> frames from <source> into the buffer, starting at <startPos>
void StandardBuffer::copyData(void *source, long startPos, long frameCount)
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

