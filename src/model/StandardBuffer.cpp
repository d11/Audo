#include "StandardBuffer.h"
#include <QString>
#include <QDebug>

// Constructor
StandardBuffer::StandardBuffer(long frameCount, int sampleRate, QString name)
 : Buffer(sampleRate, name),
   mFrames(frameCount),
   m_owned(true)
{
   qDebug() << "Initializing concrete buffer with name '" << name << "'";
	mData = new float[frameCount];
}

StandardBuffer::StandardBuffer(long frameCount, int sampleRate, QString name, float *data) 
 : Buffer(sampleRate, name),
   mFrames(frameCount),
   mData(data),
   m_owned(false)
{
   qDebug() << "Initializing concrete buffer from existing data, with name '" << name << "'";
}

// Destructor
StandardBuffer::~StandardBuffer()
{
   if (m_owned)
   {
      qDebug() << "Freeing concrete buffer '" << name << "'";
      delete[] mData;
   }
}

inline long StandardBuffer::getNumberOfSamples() { return mFrames; }
inline double StandardBuffer::getSample(long index) { return mData[index]; }

//	Copy <frameCount> frames from <source> into the buffer, starting at <startPos>
void StandardBuffer::copyData(void *source, long startPos, long frameCount)
{
   qDebug() << "Copying data into buffer...";
	try {
		if (startPos + frameCount > mFrames) throw;
		memcpy(mData + startPos*sizeof(float), source, sizeof(float)*frameCount);
	}
	catch (...) {
      qDebug() << "Error: attempted to copy too many frames into a buffer!";
	}
}

