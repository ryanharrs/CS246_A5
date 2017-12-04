#include "boardcell.h"

BoardCell::BoardCell(int row, int col, char type) : row{row}, col{col}, type{type}, bp{nullptr} {}

Info BoardCell::getInfo(){
	return {row, col, type, bp};
}
void BoardCell::setType(char getType) {
	type = getType;
	notifyObservers();
}

void BoardCell::setSP(std::shared_ptr<Block> &b) {
	bp = b;
}

void BoardCell::clearSP() {
	bp = nullptr;
}

BoardCell::~BoardCell() {
}
