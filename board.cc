#include "board.h"
#include <iostream>
#include <vector>
#include <cstddef>
#undef None
using namespace std;

Board::~Board(){
  delete td;
  delete gd;
}

void Board::setObserver(Observer<Info, State> *setob){
}

bool Board::isFull() const{
}


Colour Board::whoWon() const{
}


void Board::init(){
  theBoard.clear();
  int size = 11;
  delete td;
  td = new TextDisplay();
  gd = new GraphicsDisplay(11, 800);
  for (int row = 0; row < 18; row++) {
    vector<Cell> theRow;
    for (int column = 0; column < 11; column++) {
      Cell newCell{row, column};
      newCell.attach(td);
      theRow.emplace_back(newCell);
    }
    theBoard.emplace_back(theRow);
  }
 
  
}
void Board::setPiece(Block &b){
  draw(b);
	
}

void Board::draw(Block &b){
	for(int i = 0; i < b.height; i++){
		for(int j = 0; j < b.width; j++){
			theBoard[i+b.x][j+b.y].toggle(b.blockGrid[i][j].getInfo().blockType);
		}
	}
}

void Board::erase(Block &b){


}

void Board::toggle(size_t r, size_t c){
}

std::ostream &operator<<(std::ostream &out, const Board &b){
  out << *b.td;
  return out;
}


