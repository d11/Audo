#pragma once

#include "Buffer.h"
#include <QString>

class StandardBuffer : public Buffer {
public:
   StandardBuffer(t_audoNSamples frameCount, int sampleRate, QString name);
   StandardBuffer(t_audoNSamples frameCount, int sampleRate, QString name, float *data);
   virtual ~StandardBuffer();
   t_audoNSamples getNumberOfSamples() const;
   double getSample(t_audoNSamples index) const;
   void copyData(void *source, t_audoNSamples startPos, t_audoNSamples frameCount);

protected:
   t_audoNSamples    m_frames;
   float * m_data;
   bool    m_owned;
};
