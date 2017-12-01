#include "board.h"
#include <iostream>

#include <cstddef>
#undef None
using namespace std;

Board::~Board(){
  delete td;
}

void Board::init(int level){
  currLevel = level;
  delete td;
  td = new TextDisplay;
  theBoard.clear();
  for (size_t row = 0; row < 18; row++) {
    vector<Cell> theRow;
    for (size_t column = 0; column < 11; column++) {
      Cell newCell{row, column};
      newCell.attach(td);
      theRow.emplace_back(newCell);
    }
    theBoard.emplace_back(theRow);
  }
}

void Board::levelup(){
	currLevel++;
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


void Board::checkRows(Block &b, int level){
	int rowsCleared = 0;
  	for(int q = 0; q < b.blockRows.size(); q++){
		int i = b.blockRows[q];
		if(i >=0){	
			if(checkIndividualRow(theBoard[i]) == true){
				rowsCleared++;
				for(int j = 0; j < theBoard[i].size(); j++){
					theBoard[i][j].setPiece(BlockType::None, Colour::None);
				}
				for(int k = i; k > 0; k--){
					for(int l = 0; l < theBoard[k].size(); l++){
						theBoard[k][l].setPiece(theBoard[k-1][l].getInfo().type, theBoard[k-1][l].getInfo().colour);
					}
				}
			}	
		}
		
	}
	if(rowsCleared > 0){
		currScore += ((level + rowsCleared) * (level + rowsCleared));
	}
}
int Board::getCurrScore(){
	return currScore;
}


void Board::dropBlock(Block &b, int level) {
  while (isEmpty(b)) {
      b.moveDown();
  }
  b.moveUp();
  newBlock(b);
  checkRows(b, level);
 if(currScore > highScore){
	highScore = currScore;
 }
}


void Board::setPiece(size_t r, size_t c, BlockType type, Colour colour) {
  theBoard[r][c].setPiece(type, colour);
}

std::ostream &operator<<(std::ostream &out, const Board &b){
  out<<"Level:";
  out<<std::right<<std::setw(6)<< b.currLevel<<endl;
  out<<"Score:";
  out<<std::right<<std::setw(6)<< b.currScore<<endl;
  out<<"Hi Score:";
  out<<std::right<<std::setw(3)<< b.highScore<<endl; 
  out << *b.td;
  
  return out;
}
