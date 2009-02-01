#ifndef _AUDIOREADER_H_
#define _AUDIOREADER_H_

#include <sndfile.h>
#include "StandardBuffer.h"

class AudioReader {
   public:
   static Buffer &loadAudio(const char *filePath);
};
#endif /* _SRC/AUDIOREADER.H_ */
