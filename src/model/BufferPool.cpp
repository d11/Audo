#include "util/AudoTypes.h"
#include "input/AudioReader.h"

#include "BufferPool.h"
#include "EmptyBuffer.h"
#include "StandardBuffer.h"

BufferPool::BufferPool()
 : m_blockSize(1024)
{ }

BufferPool::~BufferPool() { }

std::list<BufferRef> BufferPool::getBuffers() {
   return m_usedBuffers;
}

BufferRef BufferPool::getNewBuffer(t_audoNSamples size) {
   t_audoSample sampleRate = 44100; // TODO
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

void BufferPool::getMoreSpace(t_audoNSamples minRequired) {
   int buffersNeeded = minRequired / m_blockSize + 1;
   for (int i = 0; i < buffersNeeded; ++i)
   {
      addBuffer();
   }
}


void BufferPool::addBuffer() {
   t_audoSample sampleRate = 44100; // TODO
   StandardBuffer *newBuffer = new StandardBuffer(m_blockSize, sampleRate, "");
   m_freeBuffers.push_front(*newBuffer); // TODO don't copy! use a BufferRef ?
 
}
