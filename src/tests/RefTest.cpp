#include <cppunit>
#include <string>

class RefTest : public CppUnit::TestCase {
   public:
      RefTest( std::string name ) : CppUnit::TestCase(name) {}

      void runTest()
      {
         std::string resource("[Test Resource]");

         // Test equality
         CPPUNIT_ASSERT( Ref(resource) == Ref(resource) );
      }
};
