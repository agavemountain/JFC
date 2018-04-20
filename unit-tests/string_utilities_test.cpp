#include <cppunit/extensions/HelperMacros.h>
#include <string_utilities.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy


class string_utilities_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( string_utilities_test );
    CPPUNIT_TEST( test_replace );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_replace()
    {
        std::string original = "this is string example....wow!!! this is really string";
        std::string replace_this = "is";
        std::string with_this = "was";
        std::string expected = "thwas was string example....wow!!! thwas was really string";

        replace (original, replace_this, with_this);

        CPPUNIT_ASSERT_EQUAL ( expected, original );
    }


};

CPPUNIT_TEST_SUITE_REGISTRATION( string_utilities_test );

