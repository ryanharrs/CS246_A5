#include <iostream>
#include "graphicsdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay():
 blockWidth{11}, blockHeight{18}, widthSize{500}, heightSize{800}, recWidthSize{widthSize/blockWidth}, recHeightSize{heightSize/blockHeight},xw{widthSize, heightSize}{
  
  xw.fillRectangle(0, 0, widthSize, heightSize, Xwindow::White);
  //xw.drawString(0,0, levelString);
  //xw.drawString(0, 10, scoreString);
  //xw.drawString(0,20, highsScoreString);
}


void GraphicsDisplay::notify(Subject<Info, State> &whoNotified) {
  auto info = whoNotified.getInfo();

  int cellWidth = widthSize / blockWidth;
  int cellHeight = heightSize/blockHeight;
  switch(info.type) {
   case BlockType::S:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight, Xwindow::Green);
    break;
   case BlockType::I:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight, Xwindow::Cyan);
    break;
   case BlockType::J:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight, Xwindow::Orange);
    break;
   case BlockType::L:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight, Xwindow::Blue);
    break;
   case BlockType::O:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight, Xwindow::Yellow);
    break;
   case BlockType::Z:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight,Xwindow::Red);
    break;
    case BlockType::T:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight, Xwindow::Purple);
    break;
   default:
    xw.fillRectangle(info.col * cellWidth, info.row * cellHeight, cellWidth, cellHeight, Xwindow::White);
  }
}
