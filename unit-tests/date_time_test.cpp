#include <cppunit/extensions/HelperMacros.h>
#include <date_time.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy tonight.

class date_time_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( date_time_test );
    CPPUNIT_TEST( test_get_current_year );
    CPPUNIT_TEST( test_get_current_year_as_string );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_get_current_year()
    {
        CPPUNIT_ASSERT_EQUAL(get_current_year_as_int(), 2018);
    }

    void test_get_current_year_as_string()
    {

    }

}; //class

CPPUNIT_TEST_SUITE_REGISTRATION( date_time_test );
