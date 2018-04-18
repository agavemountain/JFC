/*
 * Copyright 2015 Atria Dynamics, LLC.
 *
 * Written by Joe Turner <joe@atriadynamics.com>
 #
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cppunit/extensions/HelperMacros.h>
#include <environment.hpp>
using namespace JFC;
using namespace std;   // so sue me, I'm lazy tonight.



class environment_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( environment_test );
    CPPUNIT_TEST( test_get );
    CPPUNIT_TEST( test_exists );
    CPPUNIT_TEST( test_home );
    CPPUNIT_TEST( test_set_and_erase );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_get()
    {
        Environment env;
        const char *HOME= "HOME";
        char const *home = getenv("HOME");

        string strhome = env.get(HOME);
        CPPUNIT_ASSERT( strhome == home );

        strhome = HOME;
        CPPUNIT_ASSERT( env.get(strhome) == home);

        CPPUNIT_ASSERT( env[strhome] == home);
        CPPUNIT_ASSERT( env[HOME] == home);
    }

    void test_exists()
    {
        Environment env;
        const char *xyz="XZVSS123";
        const char *home="HOME";

        CPPUNIT_ASSERT( !env.isExists(xyz) );
        CPPUNIT_ASSERT( env.isExists(home) );

        string tmp = xyz;
        CPPUNIT_ASSERT( !env.isExists( tmp ) );
        tmp = home;
        CPPUNIT_ASSERT( env.isExists(  tmp ) );
    }

    void test_home()
    {
        Environment env;
        char const *home = getenv("HOME");
        CPPUNIT_ASSERT( env.home_path() == home);
    }

    void test_set_and_erase()
    {
        Environment env;
        const char *xyz="XZVSS123";
        CPPUNIT_ASSERT( !env.isExists(xyz) );
        CPPUNIT_ASSERT( !env.set(xyz, xyz));
        CPPUNIT_ASSERT( env.get(xyz) == xyz);
        CPPUNIT_ASSERT( env.isExists(xyz) );
        CPPUNIT_ASSERT( !env.erase(xyz));
        CPPUNIT_ASSERT( !env.isExists(xyz) );
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( environment_test );
