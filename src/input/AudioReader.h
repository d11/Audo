#pragma once

#include <sndfile.h>
#include "model/StandardBuffer.h"
#include "model/BufferRef.h"

class AudioReader {
   public:
   static BufferRef loadAudio(const QString & filePath);
};
