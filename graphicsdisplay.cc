#include <iostream>
#include "graphicsdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int gridSize, int winSize):
 gridSize{gridSize}, winSize{winSize}, recSize{winSize/gridSize}, xw{winSize, winSize}{
  xw.fillRectangle(0, 0, winSize, winSize, Xwindow::White);
}


void GraphicsDisplay::notify(Subject<Info, State> &whoNotified) {
  auto info = whoNotified.getInfo();
cout<<"hi there"<<endl;
  int cellSize = winSize / gridSize;
  switch(info.type) {
   case BlockType::S:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Green);
    break;
   case BlockType::I:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Cyan);
    break;
   case BlockType::J:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Orange);
    break;
   case BlockType::L:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Blue);
    break;
   case BlockType::O:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Yellow);
    break;
   case BlockType::Z:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Red);
    break;
    case BlockType::T:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Purple);
    break;
   default:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::White);
  }
}
