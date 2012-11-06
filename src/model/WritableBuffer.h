#pragma once

#include "model/StandardBuffer.h"
#include "model/Ref.h"

class WritableBuffer : public StandardBuffer
{
public:
   WritableBuffer(t_audoNSamples frameCount, t_audoNSamples sampleRate, QString name);
   WritableBuffer(t_audoNSamples frameCount, t_audoNSamples sampleRate, QString name, float *data);

   float *getDataPointer();
};

typedef Ref<WritableBuffer>::type WritableBufferRef;

