#pragma once

#include "model/BufferRef.h"
#include "model/StandardBuffer.h"
#include <list>
#include "util/AudoTypes.h"

class BufferPool {
   private:
      std::list<StandardBuffer> freeBuffers;
      std::list<BufferRef> usedBuffers;
      const frames_t blockSize;

   public:
      // Ctor
      BufferPool();

      // Dtor
      ~BufferPool();

      // Provide a silent buffer of the specified size
      BufferRef getNewBuffer(frames_t size);

      BufferRef getNewBufferFromFile(QString fileName);

      // Provide a buffer of zero length
      BufferRef getEmptyBuffer();

      // Return a list of the buffers in the pool
      std::list<BufferRef> getBuffers();

   private:
      // Allocate more space (at least minRequired extra frames)
      void getMoreSpace(frames_t minRequired);
      
      
      void addBuffer();
};
