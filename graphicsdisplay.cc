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
  int cellSize = winSize / gridSize;
  switch(info.blockType) {
   case 'S':
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Green);
    break;
   case 'I':
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Cyan);
    break;
   case 'J':
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Orange);
    break;
   case 'L':
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Blue);
    break;
   case 'O':
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Yellow);
    break;
   case 'Z':
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Red);
    break;
    case 'T':
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Purple);
    break;
   default:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::White);
  }
}
