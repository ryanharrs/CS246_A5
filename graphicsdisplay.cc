#include <iostream>
#include "graphicsdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay():
 blockWidth{11}, blockHeight{19}, widthSize{515},heightSize{705},  sidePanelWidth{150}, recWidthSize{(widthSize-sidePanelWidth)/blockWidth}, recHeightSize{heightSize/blockHeight},xw{widthSize, heightSize}{
  
  xw.fillRectangle(0, heightSize/blockHeight, widthSize - sidePanelWidth, heightSize, Xwindow::Gray);
  xw.drawString(10,24, "Level:");
  xw.drawString(80,24, "0");
  xw.drawString(130, 24, "Score:");
  xw.drawString(190,24, "0");
  xw.drawString(260,24, "Hi Score:");
  xw.drawString(340,24, "0");
  xw.drawString(0, heightSize/blockHeight - 5,  "__________________________________________________________________________________________");
}


void GraphicsDisplay::notify(Subject<Info, State> &whoNotified) {
  auto info = whoNotified.getInfo();

  int cellWidth = (widthSize-sidePanelWidth) / blockWidth;
  int cellHeight = heightSize/blockHeight;
  switch(info.type) {
   case BlockType::S:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Green);
    break;
   case BlockType::I:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Cyan);
    break;
   case BlockType::J:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1)* cellHeight, cellWidth, cellHeight, Xwindow::Orange);
    break;
   case BlockType::L:
    xw.fillRectangle(info.col * cellWidth,(info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Blue);
    break;
   case BlockType::O:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Yellow);
    break;
   case BlockType::Z:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight,Xwindow::Red);
    break;
    case BlockType::T:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1)* cellHeight, cellWidth, cellHeight, Xwindow::Purple);
    break;
   default:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Gray);
  }
}
