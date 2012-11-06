#include "StandardBuffer.h"
#include <QString>
#include <QDebug>

// Constructor
StandardBuffer::StandardBuffer(t_audoNSamples frameCount, int sampleRate, QString name)
 : Buffer(sampleRate, name),
   m_frames(frameCount),
   m_owned(true)
{
   qDebug() << "Initializing concrete buffer with name '" << name << "'";
	m_data = new float[frameCount];
}

StandardBuffer::StandardBuffer(t_audoNSamples frameCount, int sampleRate, QString name, float *data) 
 : Buffer(sampleRate, name),
   m_frames(frameCount),
   m_data(data),
   m_owned(false)
{
   qDebug() << "Initializing concrete buffer from existing data, with name '" << name << "'";
}

// Destructor
StandardBuffer::~StandardBuffer()
{
   if (m_owned)
   {
      qDebug() << "Freeing concrete buffer '" << getName() << "'";
      delete[] m_data;
   }
}

inline t_audoNSamples StandardBuffer::getNumberOfSamples() const
{
   return m_frames;
}

inline t_audoSample StandardBuffer::getSample(t_audoNSamples index) const
{
   return m_data[index];
}

//	Copy <frameCount> frames from <source> into the buffer, starting at <startPos>
void StandardBuffer::copyData(void *source, t_audoNSamples startPos, t_audoNSamples frameCount)
{
   qDebug() << "Copying data into buffer...";
	try {
		if (startPos + frameCount > m_frames) throw;
		memcpy(m_data + startPos*sizeof(float), source, sizeof(float)*frameCount);
	}
	catch (...) {
      qDebug() << "Error: attempted to copy too many frames into a buffer!";
	}
}

