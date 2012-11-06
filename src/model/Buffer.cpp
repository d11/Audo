#include "Buffer.h"
#include "util/AudoTypes.h"

#include <QString>

Buffer::Buffer(t_audoNSamples sampleRate, const QString & name)
 : m_name(name),
   m_sampleRate(sampleRate)
{ }

Buffer::~Buffer()
{ }

//	Calculate the duration (in seconds) of the buffer
t_audoTime Buffer::getDuration() const
{
   return static_cast<t_audoTime>(getNumberOfSamples()) / static_cast<t_audoTime>(m_sampleRate);
}

// Return the name that was assigned to the buffer
const QString &Buffer::getName() const
{
	return m_name;
}

t_audoNSamples Buffer::getSampleRate() const
{
   return m_sampleRate;
}
