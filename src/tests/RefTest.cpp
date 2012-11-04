#include <cppunit/TestCase.h>
#include <string>
#include <iostream>

#include "model/Ref.h"

class RefTest : public CppUnit::TestCase {
   public:
      RefTest( std::string name ) : CppUnit::TestCase(name) {}

      void runTest()
      {
         std::string *resource = new std::string("[Test Resource]");

         // Test equality
         CPPUNIT_ASSERT( Ref<std::string>(resource) == Ref<std::string>(resource) );
      }
};

int main(int argc, char *argv[])
{
   RefTest refTest("Test smart pointer");
   refTest.runTest();
   std::cout << "Tests completed successfully" << std::endl;
}
