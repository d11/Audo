
#include "model/StandardBuffer.h"
#include "util/AudoTypes.h"
#include "model/WritableBuffer.h"

WritableBuffer::WritableBuffer(t_audoNSamples frameCount, t_audoNSamples sampleRate, QString name)
 : StandardBuffer(frameCount, sampleRate, name)
{ }

WritableBuffer::WritableBuffer(t_audoNSamples frameCount, t_audoNSamples sampleRate, QString name, float *data)
 : StandardBuffer(frameCount, sampleRate, name, data)
{ }


float *WritableBuffer::getDataPointer()
{
   return m_data;
}
