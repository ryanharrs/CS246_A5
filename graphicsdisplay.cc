#include "graphicsdisplay.h"

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
  xw.drawString(widthSize - sidePanelWidth + 20, heightSize/blockHeight + 20, "Next Block:");	
}

void GraphicsDisplay::updateScore(int newScore){
	string score = to_string(newScore);
	xw.fillRectangle(190, 24, 50, 20, Xwindow::White);
	xw.drawString(190, 24, score);

}

void GraphicsDisplay::updateHighScore(int newHighScore){
	string highScore = to_string(newHighScore);
	xw.fillRectangle(340, 24, 50, 20, Xwindow::White);
	xw.drawString(190, 24, highScore);

}

void GraphicsDisplay::updateLevel(int newLevel){
	string level = to_string(newLevel);
	xw.fillRectangle(190, 24, 50, 20, Xwindow::White);
	xw.drawString(10, 24, level);

}

void GraphicsDisplay::drawNextBlock(Block &b){
	
}

void GraphicsDisplay::notify(Subject<Info> &whoNotified) {
  auto info = whoNotified.getInfo();

  int cellWidth = (widthSize-sidePanelWidth) / blockWidth;
  int cellHeight = heightSize/blockHeight;
  switch(info.type) {
   case '?':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Black);
    break;
   case '*':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Brown);
    break;
   case 'S':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Green);
    break;
   case 'I':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Cyan);
    break;
   case 'J':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1)* cellHeight, cellWidth, cellHeight, Xwindow::Orange);
    break;
   case 'L':
    xw.fillRectangle(info.col * cellWidth,(info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Blue);
    break;
   case 'O':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Yellow);
    break;
   case 'Z':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight,Xwindow::Red);
    break;
    case 'T':
    xw.fillRectangle(info.col * cellWidth, (info.row + 1)* cellHeight, cellWidth, cellHeight, Xwindow::Purple);
    break;
   default:
    xw.fillRectangle(info.col * cellWidth, (info.row + 1) * cellHeight, cellWidth, cellHeight, Xwindow::Gray);
  }
}
