#include <cppunit/extensions/HelperMacros.h>
#include <string_utilities.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy


class string_utilities_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( string_utilities_test );
    CPPUNIT_TEST( test_replace );
    CPPUNIT_TEST( test_replace_copy );
    CPPUNIT_TEST( test_wordwrap );
    CPPUNIT_TEST( test_left_justify );
    CPPUNIT_TEST( test_right_justify );
    CPPUNIT_TEST( test_center_justify );
    CPPUNIT_TEST( test_left_justify_copy );
    CPPUNIT_TEST( test_right_justify_copy );
    CPPUNIT_TEST( test_center_justify_copy );
    CPPUNIT_TEST( test_reverse_string );
    CPPUNIT_TEST( test_reverse_string_copy );
    CPPUNIT_TEST( test_to_lower_case );
    CPPUNIT_TEST( test_to_upper_case );
    CPPUNIT_TEST( test_chop );
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

    void test_replace_copy()
    {
        //! \todo implement unit test
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
        string source = "hello world";  //
        string expected = "    hello world     ";

        // source less than number of characters, just leave it alone.
        CPPUNIT_ASSERT_EQUAL(source, right_justify_copy(source, 3)) ;
        CPPUNIT_ASSERT_EQUAL(expected, right_justify_copy(source, 20));

    }

    void test_left_justify_copy()
    {
        //! \todo implement unit test
    }

    void test_right_justify_copy ()
    {
        //! \todo implement unit test
    }

    void test_center_justify_copy()
    {
        //! \todo implement unit test
    }

    void test_reverse_string_copy()
    {
        string target = "1234567890";
        string expected = "0987654321";
        reverse_string(target);
        CPPUNIT_ASSERT_EQUAL(expected, target);
    }

    void test_reverse_string()
    {
        string target = "1234567890";
        string expected = "0987654321";

        string actual = reverse_string_copy(target);
        CPPUNIT_ASSERT_EQUAL(expected, actual);
    }

    void test_to_lower_case()
    {
        string target = "HELLO world";
        string expected = "hello world";

        to_lower_case(target);
        CPPUNIT_ASSERT_EQUAL(expected, target);
    }

    void test_to_upper_case()
    {
        string target = "HELLO world";
        string expected = "HELLO WORLD";

        to_upper_case(target);
        CPPUNIT_ASSERT_EQUAL(expected, target);
    }


    void test_chop()
    {
        string frog = "frog";
        char ch = chop(frog);

        printf("ch = %c",ch);
        CPPUNIT_ASSERT_EQUAL(ch, 'g');
        CPPUNIT_ASSERT(frog ==  "fro");

        frog = "";
        ch = chop(frog);
        CPPUNIT_ASSERT_EQUAL(ch, '\0');
        CPPUNIT_ASSERT(frog == "");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( string_utilities_test );

