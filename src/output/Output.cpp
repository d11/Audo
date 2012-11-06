#include "output/Output.h"
#include "model/WritableBuffer.h"
#include "model/SampleInterval.h"
#include "util/AudoTypes.h"

Output::Output()
 : StreamLogger(std::cerr),
   m_time(0.0f)
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

   t_audoNSamples sampleCount = outputBuffer->getNumberOfSamples();

   // TODO ?
   t_audoNSamples sampleRate = outputBuffer->getSampleRate();

   std::cout << "time : " << m_time << std::endl;
   SampleInterval sampleInterval(m_time * sampleRate, m_time * sampleRate + sampleCount);
   m_sampleSource->getSamples(sampleInterval, outputBuffer);
   m_time += sampleCount / (t_audoTime)sampleRate;
}
