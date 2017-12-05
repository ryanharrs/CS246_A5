#include "graphicsdisplay.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay():
 blockWidth{11}, blockHeight{19}, widthSize{515},heightSize{705},  sidePanelWidth{150}, recWidthSize{(widthSize-sidePanelWidth)/blockWidth}, recHeightSize{heightSize/blockHeight},xw{widthSize, heightSize}{
  
  xw.fillRectangle(0, heightSize/blockHeight, widthSize - sidePanelWidth, heightSize, Xwindow::Gray);
  xw.drawString(10,24, "Level:");
  xw.drawString(80,24, level);
  xw.drawString(130, 24, "Score:");
  xw.drawString(190,24, score);
  xw.drawString(260,24, "Hi Score:");
  xw.drawString(340,24, highScore);
  xw.drawString(0, heightSize/blockHeight - 5,  "__________________________________________________________________________________________");
  xw.drawString(widthSize - sidePanelWidth + 20, heightSize/blockHeight + 20, "Next Block:"); 
}

void GraphicsDisplay::updateScore(int newScore){
  score = to_string(newScore);
  xw.clearArea(0, 0, 0, 30);
  xw.drawString(10,24, "Level:");
  xw.drawString(80,24, level);
  xw.drawString(130, 24, "Score:");
  xw.drawString(190,24, score);
  xw.drawString(260,24, "Hi Score:");
  xw.drawString(340,24, highScore);

}

void GraphicsDisplay::updateHighScore(int newHighScore){
  highScore = to_string(newHighScore);
  xw.clearArea(0, 0, 0, 30);
  xw.drawString(10,24, "Level:");
  xw.drawString(80,24, level);
  xw.drawString(130, 24, "Score:");
  xw.drawString(190,24, score);
  xw.drawString(260,24, "Hi Score:");
  xw.drawString(340,24, highScore);

}

void GraphicsDisplay::updateLevel(int newLevel){
  level = to_string(newLevel);
  xw.clearArea(0, 0, 0, 30);
  xw.drawString(10,24, "Level:");
  xw.drawString(80,24, level);
  xw.drawString(130, 24, "Score:");
  xw.drawString(190,24, score);
  xw.drawString(260,24, "Hi Score:");
  xw.drawString(340,24, highScore);

}

void GraphicsDisplay::updateNextBlock(shared_ptr<Block> &b){
  
  int cellWidth = 30;
  int cellHeight = 30;
  int a = widthSize - sidePanelWidth + 20;
  int r = 15;
  xw.clearArea(a - 20, cellHeight * 3, 150,150);
  for(int idx = 0; idx < 4; idx++){
    auto info = b->getCell(idx);
    string type = to_string(b->getType());
    switch(b->getType()) {
          case '?':
          xw.fillRectangle(info.col * cellWidth + a,(info.row + 1) * cellHeight - r, cellWidth, cellHeight, Xwindow::Black);
          break;
        case '*':
          xw.fillRectangle(info.col * cellWidth + a,(info.row + 1) * cellHeight - r, cellWidth, cellHeight, Xwindow::Brown);
          break;
        case 'S':
          xw.fillRectangle(info.col * cellWidth+ a,(info.row + 1) * cellHeight- r, cellWidth, cellHeight, Xwindow::Green);
          break;
        case 'I':
          xw.fillRectangle(info.col * cellWidth + a, (info.row + 1) * cellHeight - r, cellWidth, cellHeight, Xwindow::Cyan);
          break;
        case 'J':
          xw.fillRectangle(info.col * cellWidth + a, (info.row + 1)* cellHeight- r, cellWidth, cellHeight, Xwindow::Orange);
          break;
          case 'L':
          xw.fillRectangle(info.col * cellWidth + a, (info.row + 1) * cellHeight - r, cellWidth, cellHeight, Xwindow::Blue);
          break;
        case 'O':
          xw.fillRectangle(info.col * cellWidth + a, (info.row + 1) * cellHeight - r, cellWidth, cellHeight, Xwindow::Yellow);
          break;
        case 'Z':
          xw.fillRectangle(info.col * cellWidth + a, (info.row + 1) * cellHeight - r, cellWidth, cellHeight,Xwindow::Red);
          break;
        case 'T':
          xw.fillRectangle(info.col * cellWidth + a, (info.row + 1)* cellHeight - r, cellWidth, cellHeight, Xwindow::Purple);
          break;
        default:
          xw.fillRectangle(info.col * cellWidth + a, (info.row + 1) * cellHeight - r, cellWidth, cellHeight, Xwindow::Gray);
  }
  
  }
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
