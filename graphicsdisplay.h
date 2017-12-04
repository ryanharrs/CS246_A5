#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"
#include "info.h"
#include "subject.h"
#include "block.h"
#include <string>
#include <memory>

class GraphicsDisplay: public Observer<Info> {
  const int blockWidth, blockHeight, widthSize, heightSize, sidePanelWidth, recWidthSize, recHeightSize;
  Xwindow xw;
  std::string level = std::to_string(0);
  std::string score = std::to_string(0);  
  std::string highScore = std::to_string(0);
 public:
  GraphicsDisplay();
  void updateScore(int newScore);
  void updateHighScore(int newHighScore);
  void updateLevel(int newLevel);
  void updateNextBlock(std::shared_ptr<Block> &b);
  void notify(Subject<Info> &whoNotified) override;
};
#endif
