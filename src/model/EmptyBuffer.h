#pragma once

#include <QString>

#include "Buffer.h"
#include "util/AudoTypes.h"

class EmptyBuffer : public Buffer {
	public:
		EmptyBuffer(t_audoNSamples frameCount, t_audoNSamples sampleRate);
		virtual ~EmptyBuffer();
      t_audoNSamples getNumberOfSamples() const;
      t_audoSample getSample(t_audoNSamples index) const;

	protected:
		t_audoNSamples frames;
};

