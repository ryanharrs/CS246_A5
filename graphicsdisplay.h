#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"
#include "info.h"
#include "subject.h"
class Cell;

class GraphicsDisplay: public Observer<Info> {
  const int blockWidth, blockHeight, widthSize, heightSize, sidePanelWidth, recWidthSize, recHeightSize;
  Xwindow xw;
  int level = 0;
  int currScore = 0;	
  int highScore = 0;
 public:
  GraphicsDisplay();

  void notify(Subject<Info> &whoNotified) override;
};
#endif
