#include <cppunit/extensions/HelperMacros.h>
#include <string_utilities.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy


class string_utilities_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( string_utilities_test );
    CPPUNIT_TEST( test_replace );
    CPPUNIT_TEST( test_wordwrap );
    CPPUNIT_TEST( test_left_justify );
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

        CPPUNIT_ASSERT_EQUAL(replace_copy("abcdef", "foo", "bar"), string("abcdef"));
        CPPUNIT_ASSERT_EQUAL(replace_copy("abcdef", "ab", "cd"), string("cdcdef"));
        CPPUNIT_ASSERT_EQUAL(replace_copy("abcdef", "ab", ""), string("cdef"));
        CPPUNIT_ASSERT_EQUAL(replace_copy("abcabc", "ab", ""), string("cc"));
        CPPUNIT_ASSERT_EQUAL(replace_copy("abcdef", "", ""), string("abcdef"));

    }

    void test_wordwrap()
    {
        string source = "Executive Chance";
        string expected = "Executive\nChance";

        // if the source string is less than the number of characters,
        // it should be left alone.
        CPPUNIT_ASSERT_EQUAL(source, wordwrap( source, 80) ) ;

        //
        CPPUNIT_ASSERT_EQUAL(expected, wordwrap( source, 9) );
        CPPUNIT_ASSERT_EQUAL(expected, wordwrap( source, 8) );

        // BUG: if the first word is longer than the wrap column,
        // bad things will happen.
        //CPPUNIT_ASSERT_EQUAL(expected, wordwrap( source, 6) );
        //CPPUNIT_ASSERT_EQUAL(expected, wordwrap( source, 5) ) ;
    }

    void test_left_justify()
    {
        string source = "hello world";  //
        string expected = "hello world         ";

        // source less than number of characters, just leave it alone.
        CPPUNIT_ASSERT_EQUAL(source, left_justify_copy(source, 3)) ;
        CPPUNIT_ASSERT_EQUAL(expected, left_justify_copy(source, 20));

    }

    void test_right_justify()
    {
        string source = "hello world";  //
        string expected = "         hello world";

        // source less than number of characters, just leave it alone.
        CPPUNIT_ASSERT_EQUAL(source, right_justify_copy(source, 3)) ;
        CPPUNIT_ASSERT_EQUAL(expected, right_justify_copy(source, 20));

    }

    void test_center_justify()
    {
        string source = "hello  world";  //
        string expected = "     hello world     ";

        // source less than number of characters, just leave it alone.
        CPPUNIT_ASSERT_EQUAL(source, right_justify_copy(source, 3)) ;
        CPPUNIT_ASSERT_EQUAL(expected, right_justify_copy(source, 20));

    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( string_utilities_test );

