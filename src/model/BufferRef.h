#pragma once

#include "model/Ref.h"
#include "model/Buffer.h"

typedef Ref<Buffer>::type BufferRef;

//class BufferRef : public Ref<Buffer> {
//   private:
//      Buffer *ptr;
//      BufferRef() { };
//   public:
//      BufferRef(Buffer *buffer) : ptr(buffer) { }
//      ~BufferRef() { }
//      Buffer &operator *() const { return *ptr; }
//      Buffer *operator ->() const { return ptr; }
//};
