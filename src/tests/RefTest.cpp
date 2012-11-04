#include <cppunit/TestCase.h>
#include <string>
#include <iostream>

#include "model/BufferRef.h"
#include "model/StandardBuffer.h"

class RefTest : public CppUnit::TestCase {
   public:
      RefTest( std::string name ) : CppUnit::TestCase(name) {}

      void runTest()
      {
         BufferRef refA(new StandardBuffer(1, 1, "[Test Resource]"));
         BufferRef refB(refA);

         // Test equality
         CPPUNIT_ASSERT( refA == refB );
      }
};

int main(int argc, char *argv[])
{
   RefTest refTest("Test smart pointer");
   refTest.runTest();
   std::cout << "Tests completed successfully" << std::endl;
}
