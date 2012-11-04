#include "StandardBuffer.h"
#include <QString>
#include <QDebug>

// Constructor
StandardBuffer::StandardBuffer(long frameCount, int sampleRate, QString name)
 : Buffer(sampleRate, name),
   frames(frameCount)
{
   qDebug() << "Initializing concrete buffer with name '" << name << "'";
	data = new float[frameCount];
}

StandardBuffer::StandardBuffer(long frameCount, int sampleRate, QString name, float *data) 
 : Buffer(sampleRate, name),
   frames(frameCount),
   data(data)
{
   qDebug() << "Initializing concrete buffer from existing data, with name '" << name << "'";
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
		memcpy(data + startPos*sizeof(float), source, sizeof(float)*frameCount);
	}
	catch (...) {
      qDebug() << "Error: attempted to copy too many frames into a buffer!";
	}
}

