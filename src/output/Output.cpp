#include "output/Output.h"
#include "model/WritableBuffer.h"
#include "model/SampleInterval.h"

Output::Output()
 : StreamLogger(std::cerr) 
{ }

Output::~Output()
{ }

void Output::setSampleSource(const SampleSource::ref & sampleSource)
{
   m_sampleSource = sampleSource;
}

void Output::fillBuffer(WritableBufferRef & outputBuffer)
{
   if (! m_sampleSource)
   {
      log("No sample source set");
      return;
   }

   long sampleCount = outputBuffer->getNumberOfSamples();
   float time = 0;

   SampleInterval sampleInterval(0, sampleCount); // TODO time offset
   m_sampleSource->getSamples(sampleInterval, outputBuffer);
}
