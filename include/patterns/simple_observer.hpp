/*
 * @(#) simple_observer.hpp
 *
 * @author Joe Turner (joe@agavemountain.com)
 *
 * Copyright (c) 2018 Joe Turner
 * All rights reserved.
 *
 */
#ifndef _SIMPLE_OBSERVER_HPP_
#define _SIMPLE_OBSERVER_HPP_
#include <set>
namespace JFC
{
namespace Patterns
{

class SimpleSubject;


//! \brief Simple Observer (Subscriber) object
//!
//! The observer pattern is a software design pattern in
//! which an object, called the subject, maintains a list of
//! its dependents, called observers, and notifies them automatically
//! of any state changes, usually by calling one of their methods.
//!
//! This is half of the publish-subscriber/observer-subject
//! design pattern.  In a nutshell, your observer-derived class
//! registers with the subject.  Observers are notified by
//! the subject.
//!
//! \ingroup designpatterns
class SimpleObserver {
public:
  virtual void update(SimpleSubject & subject) = 0;
};


//! \brief Simple Subject (Publisher/Observable) Object.
//!
//! The subject contains a list of observers.  When a
// also knows as Observable in literature
class SimpleSubject
{
	//! collection of observers.
  std::set<SimpleObserver*> observers;

public:
  void attachObserver(SimpleObserver *o) { observers.insert(o); }
  void detachObserver(SimpleObserver *o) { observers.erase(o); }

  void notifyObservers()
  {
    for (auto &o : observers)
    {
      o->update(*this);
    }
  }

};



}
}
#endif

