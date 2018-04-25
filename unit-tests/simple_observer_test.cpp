/*
 * @(#) simple_observer_test.cpp
 *
 * @author Joe Turner (joe@agavemountain.com)
 *
 * Copyright (c) 2018 Joe Turner
 * All rights reserved.
 *
 */
#include <cppunit/extensions/HelperMacros.h>
#include <patterns/simple_observer.hpp>
using namespace JFC::Patterns;
using namespace std;   // so sue me, I'm lazy tonight.

class MyObserver : public SimpleObserver
{
public:
	int count;
	MyObserver() : count(0) {}
	virtual void update(SimpleSubject & subject) { count++; }
};

class simple_observer_test : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( simple_observer_test );
    CPPUNIT_TEST( test_observer );
    CPPUNIT_TEST_SUITE_END();
public:

    void test_observer()
    {
    	MyObserver obs;
        CPPUNIT_ASSERT_EQUAL( 0, obs.count );

        SimpleSubject sub;
        sub.attachObserver(&obs);
        CPPUNIT_ASSERT_EQUAL( 0, obs.count );

        sub.notifyObservers();
        CPPUNIT_ASSERT_EQUAL( 1, obs.count );

    }


}; //class

CPPUNIT_TEST_SUITE_REGISTRATION( simple_observer_test );
