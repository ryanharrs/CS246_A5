#include "board.h"
#include <iostream>

#include <cstddef>
#undef None
using namespace std;

Board::~Board(){
  delete td;
  delete gd;
}

void Board::init(){
 
  delete td;
  td = new TextDisplay;
  delete gd;
  gd  = new GraphicsDisplay;
  theBoard.clear();
  for (size_t row = 0; row < 18; row++) {
    vector<Cell> theRow;
    for (size_t column = 0; column < 11; column++) {
      Cell newCell{row, column};
      newCell.attach(td);
      newCell.attach(gd);
      theRow.emplace_back(newCell);
    }
    theBoard.emplace_back(theRow);
  }
}

bool Board::isEmpty(Block &b) {
    for(int idx = 0; idx < 4; idx++) {
      if (b.cellInfo(idx).col > 10) return false;
      if (b.cellInfo(idx).col < 0) return false;
      if (b.cellInfo(idx).row > 17) return false;
      if (theBoard[b.cellInfo(idx).row][b.cellInfo(idx).col].getInfo().type != BlockType::None) {
        return false;
      }
    }
    return true;
}

void Board::newBlock(Block &b) {
  for (int idx = 0; idx < 4; idx++) {
    setPiece(b.cellInfo(idx).row, b.cellInfo(idx).col, b.cellInfo(idx).type, b.cellInfo(idx).colour);
   }
}

void Board::clearBlock(Block &b) {
  for (int idx = 0; idx < 4; idx++) {
    setPiece(b.cellInfo(idx).row, b.cellInfo(idx).col, BlockType::None, b.cellInfo(idx).colour);
  }
}



bool Board::checkIndividualRow(vector<Cell> row){
	for(int i = 0; i < row.size(); i++){
		if(row[i].getInfo().type == BlockType::None){
			return false;
		}
	}
	return true;
}


void Board::checkRow(int i){
	if(i >=0){	
	if(checkIndividualRow(theBoard[i]) == true){
		for(int j = 0; j < theBoard[i].size(); j++){
			theBoard[i][j].setPiece(BlockType::None, Colour::None);
		}
	}	
	}
}



void Board::dropBlock(Block &b) {
  while (isEmpty(b)) {
      b.moveDown();
  }
  b.moveUp();
  newBlock(b);
  for(int i = 0; i < b.blockRows.size(); i++){
	checkRow(b.blockRows[i]);
  } 
}




void Board::setPiece(size_t r, size_t c, BlockType type, Colour colour) {
  theBoard[r][c].setPiece(type, colour);
}

std::ostream &operator<<(std::ostream &out, const Board &b){
  out << *b.td;
  return out;
}
