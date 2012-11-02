#include "BufferPool.h"

BufferPool::BufferPool()
   : buffers() {

}

BufferPool::~BufferPool() { }

std::list<BufferRef> &BufferPool::getBuffers() {
   return buffers;
}

BufferRef BufferPool::getNewBuffer(long size) {
   StandardBuffer *buffer = new StandardBuffer(size,)
}

BufferRef BufferPool::getEmptyBuffer() {
   return getNewBuffer(0);
}

BufferRef BufferPool::getNewBufferFromFile(QString fileName) {

}

void BufferPool::getMoreSpace(frames_t minRequired) {
   int buffersNeeded = minRequired / blockSize + 1;
   for (int i = 0; i < buffersNeeded; ++i)
      addBuffer();
}


void BufferPool::addBuffer() {
   StandardBuffer &newBuffer = new StandardBuffer(blockSize, sampleRate);
   freeBuffers.add(newBuffer);

}
