#pragma once

#include "model/AudoType.h"
#include "model/Ref.h"
#include "model/WritableBuffer.h"

class SampleInterval;

class SampleSource : public AudoType<SampleSource>
{
public:
   typedef Ref<SampleSource>::type ref;

   SampleSource();
   virtual ~SampleSource();
   virtual void getSamples(const SampleInterval & interval, const WritableBufferRef & outputBuffer) = 0;

private:
};
