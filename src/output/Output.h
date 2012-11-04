#pragma once

#include "model/BufferRef.h"

class Output {
   public:
      Output() {};
      virtual ~Output() {};
      virtual void fillBuffer(BufferRef buffer) = 0;

   private:
};
