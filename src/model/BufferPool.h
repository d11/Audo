#pragma once

#include "model/BufferRef.h"
#include "model/StandardBuffer.h"
#include <list>
#include "util/AudoTypes.h"

class BufferPool {
   public:
      // Ctor
      BufferPool();

      // Dtor
      ~BufferPool();

      // Provide a silent buffer of the specified size
      BufferRef getNewBuffer(t_audoNSamples size);

      BufferRef getNewBufferFromFile(QString fileName);

      // Provide a buffer of zero length
      BufferRef getEmptyBuffer();

      // Return a list of the buffers in the pool
      std::list<BufferRef> getBuffers();

   private:
      // Allocate more space (at least minRequired extra frames)
      void getMoreSpace(t_audoNSamples minRequired);
      
      void addBuffer();

      std::list<StandardBuffer> m_freeBuffers;
      std::list<BufferRef>      m_usedBuffers;
      const t_audoNSamples      m_blockSize;
};
