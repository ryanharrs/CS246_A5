#include <iostream>
#include "graphicsdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int gridSize, int winSize):
 gridSize{gridSize}, winSize{winSize}, recSize{winSize/gridSize}, xw{winSize, winSize}{
  xw.fillRectangle(0, 0, winSize, winSize, Xwindow::Blue);
 
	int x = gridSize / 2 - 1;	
 xw.fillRectangle(x *recSize, x*recSize, recSize, recSize, Xwindow::Black);
 xw.fillRectangle((x+1) *recSize, (x+1)*recSize, recSize, recSize, Xwindow::Black);
 xw.fillRectangle(x *recSize, (x+1)*recSize, recSize, recSize, Xwindow::White);
 xw.fillRectangle((x+1) *recSize, x*recSize, recSize, recSize, Xwindow::White);

}


void GraphicsDisplay::notify(Subject<Info, State> &whoNotified) {
  auto info = whoNotified.getInfo();
  int cellSize = winSize / gridSize;
  switch(info.colour) {
   case Colour::Black:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Black);
    break;
   case Colour::White:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::White);
    break;
   default:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Blue);
  }
}
