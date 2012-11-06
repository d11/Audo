#include "util/AudoTypes.h"
#include "Buffer.h"
#include "EmptyBuffer.h"

EmptyBuffer::EmptyBuffer(t_audoNSamples frameCount, t_audoNSamples sampleRate)
 : Buffer(sampleRate, "Empty buffer")
{ }

EmptyBuffer::~EmptyBuffer()
{ }

t_audoNSamples EmptyBuffer::getNumberOfSamples() const
{
   return frames;
}

t_audoSample EmptyBuffer::getSample(t_audoNSamples index) const
{
   return 0;
}
