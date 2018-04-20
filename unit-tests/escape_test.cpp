#include <cppunit/extensions/HelperMacros.h>
#include <escape.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy tonight.



class escape_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( escape_test );
    CPPUNIT_TEST( test_isPrintable );
    CPPUNIT_TEST( test_isControl );
    CPPUNIT_TEST( test_escapeCPP );
    CPPUNIT_TEST_SUITE_END();
public:


void test_isPrintable()
{
    for (char ch = 0; ch<0x20; ch++)
    {
        CPPUNIT_ASSERT_EQUAL( false, isPrintableASCII(ch) );
    }
}

void test_isControl()
{
    for (char ch = 0; ch<0x20; ch++)
    {
        CPPUNIT_ASSERT_EQUAL( true, isControl(ch) );
    }
}

void test_escapeCPP()
{
    const char * teststr = "\"\'\?";
    const char * testresult = "\\\"\\\'\\\?";
    const char * teststr2 = "abc";
    string tmp = teststr;
    string tmp2 = testresult;
    tmp = encode_cpp(tmp);

    CPPUNIT_ASSERT_EQUAL(tmp, tmp2);

    tmp = teststr2;
    tmp2 = teststr2;

    encode_cpp(tmp);

    CPPUNIT_ASSERT_EQUAL(tmp, tmp2);

}

}; //class

CPPUNIT_TEST_SUITE_REGISTRATION( escape_test );
