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

void Board::init() {
  theBoard.clear();
  score = 0;
  hiscore = 0;
  td = new TextDisplay;
  for (int row = 0; row < 18; row ++) {
    vector<BoardCell> theRow;
    for (int col = 0; col < 11; col ++) {
      BoardCell bc{row, col, ' '};
      bc.attach(td);
      theRow.emplace_back(bc);
    }
    theBoard.emplace_back(theRow);
  }
}

Info Board::hint(const Block&b){
	Block hintBlock(b.type, level, true);
	int hintRotation = 0;
	int hintCol = 0;
	int hintRow = 0;
	int currRow;
	int magicNum = 18 * 4;
	for(int i = 0; i < 11; i++){
		for(int r = 0; r < 4; r++){
			int currMagicNum = 0;
			currRow = 0;
			while(canPlace(currRow, i, hintBlock){
				currRow++;
			}
			currRow--;
			for(int idx = 0; idx < 4; idx++){
				currMagicNum += (hintBlock.getCell(idx).row + curr_row);
			}
			if(currMagicNum < magicNum){
				magicNum = currMagicNum;
				hintCol = i;
				hintRotation = r;
				hintRow = currRow;
			}
			b.clockwise();
		}
		
	}
	while(hintRotation != 0){
		b.counterclcokwise();
		hintRotation--;
	}
	return {hintRow, hintCol, b.type, b};	

}

bool Board::canPlace(int curr_row, int curr_col, const Block &b) {
  for (int idx = 0; idx < 4; idx++) {
    if (!isEmpty(b.getCell(idx).row + curr_row, b.getCell(idx).col + curr_col)) return false;
  }
  return true;
}

void Board::setPiece(int curr_row, int curr_col, Block &b) {
  for (int idx = 0; idx < 4; idx++) {
    theBoard[curr_row + b.getCell(idx).row][curr_col + b.getCell(idx).col].setType(b.getCell(idx).type);
    theBoard[curr_row + b.getCell(idx).row][curr_col + b.getCell(idx).col].setBP(&b);
  }
}

void Board::clearPiece (int curr_row, int curr_col, const Block &b) {
  for (int idx = 0; idx < 4; idx++) {
    theBoard[curr_row + b.getCell(idx).row][curr_col + b.getCell(idx).col].setType(' ');
    theBoard[curr_row + b.getCell(idx).row][curr_col + b.getCell(idx).col].setBP(nullptr);
  }
}

void Board::clearRows(int currLevel) {
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
          if (score > hiscore) hiscore = score;
          theBoard[row][col].delBP();
        } else {
          theBoard[row][col].getInfo().bp->decPieces();
        }
      }
      for (int row = 17; row >= 3; row --) {
        for (int col = 0; col < 11; col++) {
          theBoard[row][col].setType(theBoard[row-1][col].getInfo().type);
          theBoard[row][col].setBP(theBoard[row-1][col].getInfo().bp);
        }
      }
      ++row;
      ++linesCleared;
    }
  }
  score += (currLevel + linesCleared) * (currLevel + linesCleared);
  if (score > hiscore) hiscore = score;
}

std::ostream &operator<<(std::ostream &out, const Board &b){
  out << "Score:" << setw(7) << b.score << std::endl;
  out << "Hi Score:" << setw(4) << b.hiscore << std::endl;
  out << *b.td;
  return out;
}
