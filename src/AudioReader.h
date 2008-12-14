#ifndef _AUDIOREADER_H_
#define _AUDIOREADER_H_

#include <sndfile.h>
#include "ABuffer.h"

class AudioReader {
   public:
   static Buffer *loadAudio(const char *filePath);
};
#endif /* _SRC/AUDIOREADER.H_ */
