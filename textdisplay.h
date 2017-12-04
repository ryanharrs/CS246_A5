#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <iomanip>
#include <vector>
#include "observer.h"
#include "info.h"
#include "subject.h"

class TextDisplay: public Observer<Info> {
  std::vector<std::vector<char>> theDisplay;
 public:
  TextDisplay();

  void notify(Subject<Info> &whoNotified) override;

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
