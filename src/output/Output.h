#pragma once

#include "model/BufferRef.h"
#include "model/WritableBuffer.h"
#include "model/SampleSource.h"
#include "util/log/StreamLogger.h"

class Output : public StreamLogger {
   public:
      Output();
      virtual ~Output();

      // Specify where output should be drawn from
      void setSampleSource(const SampleSource::ref & sampleSource);


   protected:
      void fillBuffer(WritableBufferRef & outputBuffer);

   private:
      SampleSource::ref m_sampleSource;

};
