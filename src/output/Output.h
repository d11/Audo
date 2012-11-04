#pragma once

#include "model/Buffer.h"

class BufferRef;

class Output {
   public:
      Output() {};
      virtual ~Output() {};
      virtual void fillBuffer(BufferRef buffer) = 0;

   private:
};
