#include "util/AudoTypes.h"
#include "input/AudioReader.h"

#include "BufferPool.h"
#include "EmptyBuffer.h"
#include "StandardBuffer.h"

BufferPool::BufferPool()
   : blockSize(1024) {

}

BufferPool::~BufferPool() { }

std::list<BufferRef> BufferPool::getBuffers() {
   return usedBuffers;
}

BufferRef BufferPool::getNewBuffer(frames_t size) {
   sample_t sampleRate = 44100; // TODO
   StandardBuffer *buffer = new StandardBuffer(size, sampleRate, "");
   return BufferRef(buffer);
}

BufferRef BufferPool::getEmptyBuffer() {
   return BufferRef(new EmptyBuffer(1, 44100)); // TODO
}

BufferRef BufferPool::getNewBufferFromFile(QString fileName) {
   AudioReader reader;
   return reader.loadAudio(fileName);
}

void BufferPool::getMoreSpace(frames_t minRequired) {
   int buffersNeeded = minRequired / blockSize + 1;
   for (int i = 0; i < buffersNeeded; ++i)
   {
      addBuffer();
   }
}


void BufferPool::addBuffer() {
   sample_t sampleRate = 44100; // TODO
   StandardBuffer *newBuffer = new StandardBuffer(blockSize, sampleRate, "");
   freeBuffers.push_front(*newBuffer); // TODO don't copy! use a BufferRef ?
 
}
