#pragma once

#include "model/StandardBuffer.h"
#include "model/Ref.h"

class WritableBuffer : public StandardBuffer
{
public:
   WritableBuffer(long frameCount, int sampleRate, QString name);
   WritableBuffer(long frameCount, int sampleRate, QString name, float *data);

   float *getDataPointer();
};

typedef Ref<WritableBuffer>::type WritableBufferRef;

