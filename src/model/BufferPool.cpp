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
