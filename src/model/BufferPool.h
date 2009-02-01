#include "StandardBuffer.h"
#include <list>

class BufferPool {
   private:
      std::list<StandardBuffer> buffers;
      int (&references)[];

   public:
      BufferPool();
      ~BufferPool();
      BufferRef getNewBuffer(long size);
      BufferRef getEmptyBuffer();
      BufferRef getNewBufferFromFile(QString fileName);
      std::list<BufferRf> getBuffers();
};
