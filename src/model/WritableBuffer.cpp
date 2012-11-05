
#include "model/WritableBuffer.h"

WritableBuffer::WritableBuffer(long frameCount, int sampleRate, QString name)
 : StandardBuffer(frameCount, sampleRate, name)
{ }

WritableBuffer::WritableBuffer(long frameCount, int sampleRate, QString name, float *data)
 : StandardBuffer(frameCount, sampleRate, name, data)
{ }


float *WritableBuffer::getDataPointer()
{
   return mData;
}
