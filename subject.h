#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <iostream>
#include "info.h"
#include "observer.h"

/* A note on InfoType and StateType:

   We have separated the collection of fields into two parts:  its Info
   and its State.

   Info is for the parts of the subjject inherent to what it is:  its position
   and its colour.

   State is for the parts of the subject that, when changed, trigger
   notifications.  This is the information that the Observer "gets" when it
   calls getState on the subject.  It comprises the type of state, a direction,
   and a colour.  For more details, see state.h.
*/

// DO NOT MODIFY THIS FILE!

template <typename InfoType> class Observer;

template <typename InfoType> class Subject {
 public:
  std::vector<std::shared_ptr<Observer<InfoType>>> observers;
  void attach(std::shared_ptr<Observer<InfoType>> o);
  void notifyObservers();
  virtual InfoType getInfo() = 0;
};

template <typename InfoType> void Subject<InfoType>::attach(std::shared_ptr<Observer<InfoType>> o) {
  observers.emplace_back(o);
}

template <typename InfoType> void Subject<InfoType>::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

#endif
