#pragma once

#include "model/Buffer.h"

class BufferRef {
   private:
      Buffer *ptr;
      BufferRef() { };
   public:
      BufferRef(Buffer *buffer) : ptr(buffer) { }
      ~BufferRef() { }
      Buffer &operator *() const { return *ptr; }
      Buffer *operator ->() const { return ptr; }
};
