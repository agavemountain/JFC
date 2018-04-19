#include <cppunit/extensions/HelperMacros.h>
#include <environment.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy


class string_utilities_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( string_utilities_test );
    CPPUNIT_TEST( test );
    CPPUNIT_TEST_SUITE_END();
public:

    void test()
    {
        CPPUNIT_ASSERT( true );
    }


};

CPPUNIT_TEST_SUITE_REGISTRATION( string_utilities_test );

