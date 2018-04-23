#include <cppunit/extensions/HelperMacros.h>
#include <file_utilities.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy tonight.


class file_utilities_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( file_utilities_test );
    CPPUNIT_TEST( test_doesFileExist );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_doesFileExist()
    {
        const char *file_to_check = "testxyz.dat";
        remove(file_to_check);
        CPPUNIT_ASSERT_EQUAL (false, doesFileExist(file_to_check));
        touch(file_to_check);
        CPPUNIT_ASSERT_EQUAL (true, doesFileExist(file_to_check));

    }


}; //class

CPPUNIT_TEST_SUITE_REGISTRATION( file_utilities_test );
