#include "Buffer.h"
#include "EmptyBuffer.h"

EmptyBuffer::EmptyBuffer(long frameCount, int sampleRate)
 : Buffer(sampleRate, "Empty buffer")
{ }

EmptyBuffer::~EmptyBuffer()
{ }

long EmptyBuffer::getNumberOfSamples()
{
   return frames;
}

double EmptyBuffer::getSample(long index)
{
   return 0;
}
