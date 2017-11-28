#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

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

template <typename InfoType, typename StateType> class Observer;

template <typename InfoType, typename StateType> class Subject {
  std::vector<Observer<InfoType, StateType>*> observers;
  StateType state;
 protected:
  void setState(StateType newS);
 public:
  void attach(Observer<InfoType, StateType> *o); 
  void copyObservers(Subject<InfoType, StateType> *s);
  std::vector<Observer<InfoType,StateType>*> getObservers(); 
  void notifyObservers();
  virtual InfoType getInfo() const = 0;
  StateType getState() const;
};

template <typename InfoType, typename StateType>
 std::vector<Observer<InfoType,StateType>*> Subject<InfoType,StateType>::getObservers(){
	return observers;
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::attach(Observer<InfoType, StateType> *o) {
  observers.emplace_back(o);
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::copyObservers(Subject<InfoType,StateType> *s) {
   observers.clear();
   for(int i = 0; i < s->getObservers().size(); i++){
	observers.emplace_back(s->getObservers()[i]);
   }
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::setState(StateType newS) { state = newS; }

template <typename InfoType, typename StateType>
StateType Subject<InfoType, StateType>::getState() const { return state; }
#endif
