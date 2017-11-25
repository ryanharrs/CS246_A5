#include "grid.h"
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
  delete td;
  td = new TextDisplay;
  for (int row = 0; row < 18; row++) {
    vector<Block> theRow;
    for (int column = 0; column < 11; column++) {
      Block bc{row, column};
      bc.attach(td);
      theRow.emplace_back(bc);
    }
    theBoard.emplace_back(theRow);
  }
  for (int row = 0; row < 18; row++) {
    for (int column = 0; column < 11; column++) {
            if ((row-1) >= 0) {
                if ((column-1) >=0) theBoard[row][column].attach(&theBoard[row-1][column-1]);
                theBoard[row][column].attach(&theBoard[row-1][column]);
                if ((column+1) < size) theBoard[row][column].attach(&theBoard[row-1][column+1]);
            }
            if ((row+1) < size) {
                if ((column-1) >=0) theBoard[row][column].attach(&theBoard[row+1][column-1]);
                theBoard[row][column].attach(&theBoard[row+1][column]);
                if ((column+1) < size) theBoard[row][column].attach(&theBoard[row+1][column+1]);
                }
                if ((column-1) >=0) theBoard[row][column].attach(&theBoard[row][column-1]);
                if ((column+1) < size) theBoard[row][column].attach(&theBoard[row][column+1]);
            }
    }
}

void Board::setPiece(size_t r, size_t c, Colour colour){
  
}

void Board::toggle(size_t r, size_t c){
}

std::ostream &operator<<(std::ostream &out, const Board &b){
  out << td;
}


