#include "board.h"
#include <iostream>
#include <cstddef>
#include <iomanip>
#undef None
using namespace std;

// Private methods
bool Board::isEmpty(int row, int col) {
  if (row < 0) return false;
  if (row > 17) return false;
  if (col < 0) return false;
  if (col > 10) return false;
  if (theBoard[row][col].getInfo().type == ' ') return true;
  return false;
}

// Public methods
Board::~Board() {
  delete td;
}

void Board::updateGdNextBlock(Block &b){
	gd->updateNextBlock(b);
}

void Board::init(int currLevel) {
  theBoard.clear();
  level = currLevel;
  score = 0;
  hiscore = 0;
  td = new TextDisplay;
  if(showGraphicsDisplay == true){
  gd = new GraphicsDisplay;
}
  for (int row = 0; row < 18; row ++) {
    vector<BoardCell> theRow;
    for (int col = 0; col < 11; col ++) {
      BoardCell bc{row, col, ' '};
      theRow.emplace_back(bc);
      theRow[col].attach(td);
      theRow[col].attach(gd); 	
    }
    theBoard.emplace_back(theRow);
  }
  gd->updateLevel(level);
}

void Board::setLevel(int currLevel) {
  level = currLevel;
  gd->updateLevel(level);
}

bool Board::canPlace(int curr_row, int curr_col, const shared_ptr<Block> &b) {
  for (int idx = 0; idx < b->numPieces(); idx++) {
    if (!isEmpty(b->getCell(idx).row + curr_row, b->getCell(idx).col + curr_col)) return false;
  }
  return true;
}

void Board::setPiece(int curr_row, int curr_col, shared_ptr<Block> &b) {
  if (b->getIfHint() == true){
    if(b->getIfHint() == true){
      for (int idx = 0; idx < 4; idx++) {
        theBoard[curr_row + b->getCell(idx).row][curr_col + b->getCell(idx).col].setType('?');
        theBoard[curr_row + b->getCell(idx).row][curr_col + b->getCell(idx).col].setSP(b);
      }
    } 
  } else {
    for (int idx = 0; idx < b->numPieces(); idx++) {
      theBoard[curr_row + b->getCell(idx).row][curr_col + b->getCell(idx).col].setType(b->getCell(idx).type);
      theBoard[curr_row + b->getCell(idx).row][curr_col + b->getCell(idx).col].setSP(b);
    }
  }
}

void Board::clearPiece (int curr_row, int curr_col, const shared_ptr<Block> &b) {
  for (int idx = 0; idx < b->numPieces(); idx++) {
    theBoard[curr_row + b->getCell(idx).row][curr_col + b->getCell(idx).col].setType(' ');
    theBoard[curr_row + b->getCell(idx).row][curr_col + b->getCell(idx).col].clearSP();
  }
}

void Board::placeSplit (shared_ptr<Block> &b) {
  int col = 5;
  for (int row = 17; row >= 3; row--) {
    if (canPlace(row, col, b)) {
      setPiece(row, col, b);
      break;
    }
  }
}

bool Board::clearRows() {
  bool fullRow = true;
  int linesCleared = 0;
  for (int row = 17; row >= 3; row--) {
    for (int col = 0; col < 11; col++) {
      if (theBoard[row][col].getInfo().type == ' ') {
        fullRow = false;
        break;
      }
    }
    if (fullRow) {
      for (int col = 0; col < 11; col++) {
        if (theBoard[row][col].getInfo().bp->numPieces() == 1) {
          score += (theBoard[row][col].getInfo().bp->getLevel() + 1) * (theBoard[row][col].getInfo().bp->getLevel() + 1);
	  gd->updateScore(score);
          if (score > hiscore) {
		hiscore = score;
		gd->updateHighScore(hiscore);
	  }
          theBoard[row][col].clearSP();
        } else {
          theBoard[row][col].getInfo().bp->decPieces();
        }
      }
      for (int r = row; row >= 3; r --) {
        for (int col = 0; col < 11; col++) {
          shared_ptr<Block> copy = theBoard[r-1][col].getInfo().bp;
          theBoard[r][col].setType(theBoard[r-1][col].getInfo().type);
          theBoard[r][col].setSP(copy);
        }
      }
      ++row;
      ++linesCleared;
    }
    fullRow = true;
  }
  if (linesCleared > 0) { 
    score += (level + linesCleared) * (level + linesCleared);
    gd->updateScore(score);
    if (score > hiscore) {
	hiscore = score;
	gd->updateHighScore(hiscore);
    }
    return true;
  } else {
    return false;
  }
}

Info Board::hint(shared_ptr<Block> &b){
  int hintRotation = 0;
  int hintCol = 0;
  int hintRow = 0;
  int currRow;
  int magicNum = 0;
  b->getCell(0).row;
  for(int i = 0; i < 11; i++){
    for(int r = 0; r < 4; r++){
      if(canPlace(0,i, b) == true){
        int currMagicNum = 0;
        currRow = 0;
        while(canPlace(currRow, i, b) == true){
          currRow++;
        }
        currRow--;
        for(int idx = 0; idx < 4; idx++){
          currMagicNum += (b->getCell(idx).row + currRow);
        }
    
        if(currMagicNum > magicNum){
          magicNum = currMagicNum;
          hintCol = i;
          hintRotation = r;
          hintRow = currRow;
        }
      }
    b->clockwise();
    }
  }
  while(hintRotation != 0){
    b->clockwise();
    hintRotation--;
  }
  return {hintRow, hintCol, b->getType(), b};  

}

std::ostream &operator<<(std::ostream &out, const Board &b){
  out << "Level:" << setw(6) << b.level << endl;
  out << "Score:" << setw(6) << b.score << endl;
  out << "Hiscore:" << setw(4) << b.hiscore << endl;
  out << *b.td;
  return out;
}
