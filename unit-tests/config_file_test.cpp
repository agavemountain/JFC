/*
 * Copyright 2018 Joe Turner
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
 #include <config_file.hpp>
 using namespace JFC;
 using namespace std;   // so sue me, I'm lazy tonight.


 class config_file_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( config_file_test );
    CPPUNIT_TEST( test_get );
  CPPUNIT_TEST_SUITE_END();

  public:

  void test_get()
  {
    CPPUNIT_ASSERT( true );
  }
 };

 CPPUNIT_TEST_SUITE_REGISTRATION( config_file_test );
