#include "cell.h"
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"
#include <iostream>
#undef None
using namespace std;

Cell::~Cell(){

}

Cell::Cell(size_t r, size_t c, BlockType type) : r{r}, c{c}, type{type}, colour{Colour::None}{}

Cell::Cell(size_t r, size_t c): r{r}, c{c}, type{BlockType::None}, colour{Colour::None}{}

void Cell::setPiece(BlockType getBlock, Colour getColour) {
	type = getBlock;
	colour = getColour;
	notifyObservers();	
}




Info Cell::getInfo()const{
	Info thisInfo{r,c,colour, type};
	return thisInfo;	
}

void Cell::notify(Subject<Info, State> &whoFrom){
	

}