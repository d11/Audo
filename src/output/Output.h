#include "model/Buffer.h"

class Output {
   public:
      Output() {};
      virtual ~Output() {};
      virtual void fillBuffer(const Buffer& buff) = 0;

   private:
};
