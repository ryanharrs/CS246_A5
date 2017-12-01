#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "info.h"

// DO NOT MODIFY THIS FILE!

template <typename InfoType> class Subject;
class BoardCell;

template <typename InfoType> class Observer {
 public:
  virtual void notify(Subject<InfoType> &whoFrom) = 0; // pass the Subject that called the notify method
  virtual ~Observer() = default;
};
#endif
