#pragma once

#include "model/AudoType.h"

class SampleInterval;
class WritableBufferRef;

class SampleSource : public AudoType<SampleSource>
{
public:
   SampleSource();
   virtual ~SampleSource();

   virtual void getSamples(const SampleInterval & interval, const WritableBufferRef & outputBuffer) = 0;
private:
};
