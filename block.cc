#include "block.h"

Block::~Block() {}
bool Block::getIfHint(){
	return isHint;
}

char Block::getType(){
	return blockType;
}
Block::Block(char type, int currLevel, bool isHintVar){
	isHint = isHintVar;
	blockType = type;
	blockGrid.clear();
	position = 0;
	level = currLevel;
	pieces = 4;
	if (type == 'I') {
		blockGrid.emplace_back(BlockCell {'I', 3, 0});
		blockGrid.emplace_back(BlockCell {'I', 3, 1});
		blockGrid.emplace_back(BlockCell {'I', 3, 2});
		blockGrid.emplace_back(BlockCell {'I', 3, 3});
	} else if (type == 'J') {
		blockGrid.emplace_back(BlockCell {'J', 3, 0});
		blockGrid.emplace_back(BlockCell {'J', 4, 0});
		blockGrid.emplace_back(BlockCell {'J', 4, 1});
		blockGrid.emplace_back(BlockCell {'J', 4, 2});
	} else if (type == 'L') {
		blockGrid.emplace_back(BlockCell {'L', 3, 2});
		blockGrid.emplace_back(BlockCell {'L', 4, 0});
		blockGrid.emplace_back(BlockCell {'L', 4, 1});
		blockGrid.emplace_back(BlockCell {'L', 4, 2});
	} else if (type == 'O') {
		blockGrid.emplace_back(BlockCell {'O', 3, 0});
		blockGrid.emplace_back(BlockCell {'O', 3, 1});
		blockGrid.emplace_back(BlockCell {'O', 4, 0});
		blockGrid.emplace_back(BlockCell {'O', 4, 1});
	} else if (type == 'S') {
		blockGrid.emplace_back(BlockCell {'S', 3, 1});
		blockGrid.emplace_back(BlockCell {'S', 3, 2});
		blockGrid.emplace_back(BlockCell {'S', 4, 0});
		blockGrid.emplace_back(BlockCell {'S', 4, 1});
	} else if (type == 'Z') {
		blockGrid.emplace_back(BlockCell {'Z', 3, 0});
		blockGrid.emplace_back(BlockCell {'Z', 3, 1});
		blockGrid.emplace_back(BlockCell {'Z', 4, 1});
		blockGrid.emplace_back(BlockCell {'Z', 4, 2});
	} else if (type == 'T') {
		blockGrid.emplace_back(BlockCell {'T', 3, 0});
		blockGrid.emplace_back(BlockCell {'T', 3, 1});
		blockGrid.emplace_back(BlockCell {'T', 3, 2});
		blockGrid.emplace_back(BlockCell {'T', 4, 1});
	} 
}

Block::Block(char type, int currLevel) {
	blockGrid.clear();
	position = 0;
	isHint = false;
	blockType = type;
	level = currLevel;
	pieces = 4;
	if (type == 'I') {
		blockGrid.emplace_back(BlockCell {'I', 3, 0});
		blockGrid.emplace_back(BlockCell {'I', 3, 1});
		blockGrid.emplace_back(BlockCell {'I', 3, 2});
		blockGrid.emplace_back(BlockCell {'I', 3, 3});
	} else if (type == 'J') {
		blockGrid.emplace_back(BlockCell {'J', 3, 0});
		blockGrid.emplace_back(BlockCell {'J', 4, 0});
		blockGrid.emplace_back(BlockCell {'J', 4, 1});
		blockGrid.emplace_back(BlockCell {'J', 4, 2});
	} else if (type == 'L') {
		blockGrid.emplace_back(BlockCell {'L', 3, 2});
		blockGrid.emplace_back(BlockCell {'L', 4, 0});
		blockGrid.emplace_back(BlockCell {'L', 4, 1});
		blockGrid.emplace_back(BlockCell {'L', 4, 2});
	} else if (type == 'O') {
		blockGrid.emplace_back(BlockCell {'O', 3, 0});
		blockGrid.emplace_back(BlockCell {'O', 3, 1});
		blockGrid.emplace_back(BlockCell {'O', 4, 0});
		blockGrid.emplace_back(BlockCell {'O', 4, 1});
	} else if (type == 'S') {
		blockGrid.emplace_back(BlockCell {'S', 3, 1});
		blockGrid.emplace_back(BlockCell {'S', 3, 2});
		blockGrid.emplace_back(BlockCell {'S', 4, 0});
		blockGrid.emplace_back(BlockCell {'S', 4, 1});
	} else if (type == 'Z') {
		blockGrid.emplace_back(BlockCell {'Z', 3, 0});
		blockGrid.emplace_back(BlockCell {'Z', 3, 1});
		blockGrid.emplace_back(BlockCell {'Z', 4, 1});
		blockGrid.emplace_back(BlockCell {'Z', 4, 2});
	} else if (type == 'T') {
		blockGrid.emplace_back(BlockCell {'T', 3, 0});
		blockGrid.emplace_back(BlockCell {'T', 3, 1});
		blockGrid.emplace_back(BlockCell {'T', 3, 2});
		blockGrid.emplace_back(BlockCell {'T', 4, 1});
	} 
}

void Block::clockwise() {
	char type = blockGrid[0].type;
	(position < 3) ? ++position : position = 0;
	blockGrid.clear();
	if (type == 'I') {
		if (position == 0 || position == 2) {
			blockGrid.emplace_back(BlockCell {'I', 3, 0});
			blockGrid.emplace_back(BlockCell {'I', 3, 1});
			blockGrid.emplace_back(BlockCell {'I', 3, 2});
			blockGrid.emplace_back(BlockCell {'I', 3, 3});
		} else {
			blockGrid.emplace_back(BlockCell {'I', 0, 0});
			blockGrid.emplace_back(BlockCell {'I', 1, 0});
			blockGrid.emplace_back(BlockCell {'I', 2, 0});
			blockGrid.emplace_back(BlockCell {'I', 3, 0});
		}
	} else if (type == 'J') {
		if (position == 0) {
			blockGrid.emplace_back(BlockCell {'J', 3, 0});
			blockGrid.emplace_back(BlockCell {'J', 4, 0});
			blockGrid.emplace_back(BlockCell {'J', 4, 1});
			blockGrid.emplace_back(BlockCell {'J', 4, 2});
		} else if (position == 1) {
			blockGrid.emplace_back(BlockCell {'J', 2, 0});
			blockGrid.emplace_back(BlockCell {'J', 2, 1});
			blockGrid.emplace_back(BlockCell {'J', 3, 0});
			blockGrid.emplace_back(BlockCell {'J', 4, 0});
		} else if (position == 2) {
			blockGrid.emplace_back(BlockCell {'J', 3, 0});
			blockGrid.emplace_back(BlockCell {'J', 3, 1});
			blockGrid.emplace_back(BlockCell {'J', 3, 2});
			blockGrid.emplace_back(BlockCell {'J', 4, 2});
		} else {
			blockGrid.emplace_back(BlockCell {'J', 2, 1});
			blockGrid.emplace_back(BlockCell {'J', 3, 1});
			blockGrid.emplace_back(BlockCell {'J', 4, 0});
			blockGrid.emplace_back(BlockCell {'J', 4, 1});
		}
	} else if (type == 'L') {
		if (position == 0) {
			blockGrid.emplace_back(BlockCell {'L', 3, 2});
			blockGrid.emplace_back(BlockCell {'L', 4, 0});
			blockGrid.emplace_back(BlockCell {'L', 4, 1});
			blockGrid.emplace_back(BlockCell {'L', 4, 2});
		} else if (position == 1) {
			blockGrid.emplace_back(BlockCell {'L', 2, 0});
			blockGrid.emplace_back(BlockCell {'L', 3, 0});
			blockGrid.emplace_back(BlockCell {'L', 4, 0});
			blockGrid.emplace_back(BlockCell {'L', 4, 1});
		} else if (position == 2) {
			blockGrid.emplace_back(BlockCell {'L', 3, 0});
			blockGrid.emplace_back(BlockCell {'L', 3, 1});
			blockGrid.emplace_back(BlockCell {'L', 3, 2});
			blockGrid.emplace_back(BlockCell {'L', 4, 0});
		} else {
			blockGrid.emplace_back(BlockCell {'L', 2, 0});
			blockGrid.emplace_back(BlockCell {'L', 2, 1});
			blockGrid.emplace_back(BlockCell {'L', 3, 1});
			blockGrid.emplace_back(BlockCell {'L', 4, 1});
		}
	} else if (type == 'O') {
		blockGrid.emplace_back(BlockCell {'O', 3, 0});
		blockGrid.emplace_back(BlockCell {'O', 3, 1});
		blockGrid.emplace_back(BlockCell {'O', 4, 0});
		blockGrid.emplace_back(BlockCell {'O', 4, 1});
	} else if (type == 'S') {
		if (position == 0 || position == 2) {
			blockGrid.emplace_back(BlockCell {'S', 3, 1});
			blockGrid.emplace_back(BlockCell {'S', 3, 2});
			blockGrid.emplace_back(BlockCell {'S', 4, 0});
			blockGrid.emplace_back(BlockCell {'S', 4, 1});
		} else {
			blockGrid.emplace_back(BlockCell {'S', 2, 0});
			blockGrid.emplace_back(BlockCell {'S', 3, 0});
			blockGrid.emplace_back(BlockCell {'S', 3, 1});
			blockGrid.emplace_back(BlockCell {'S', 4, 1});
		}
	} else if (type == 'Z') {
		if (position == 0 || position == 2) {
			blockGrid.emplace_back(BlockCell {'Z', 3, 0});
			blockGrid.emplace_back(BlockCell {'Z', 3, 1});
			blockGrid.emplace_back(BlockCell {'Z', 4, 1});
			blockGrid.emplace_back(BlockCell {'Z', 4, 2});
		} else {
			blockGrid.emplace_back(BlockCell {'Z', 2, 1});
			blockGrid.emplace_back(BlockCell {'Z', 3, 0});
			blockGrid.emplace_back(BlockCell {'Z', 3, 1});
			blockGrid.emplace_back(BlockCell {'Z', 4, 0});
		}
	} else if (type == 'T') {
		if (position == 0) {
			blockGrid.emplace_back(BlockCell {'T', 3, 0});
			blockGrid.emplace_back(BlockCell {'T', 3, 1});
			blockGrid.emplace_back(BlockCell {'T', 3, 2});
			blockGrid.emplace_back(BlockCell {'T', 4, 1});
		} else if (position == 1){
			blockGrid.emplace_back(BlockCell {'T', 2, 1});
			blockGrid.emplace_back(BlockCell {'T', 3, 0});
			blockGrid.emplace_back(BlockCell {'T', 3, 1});
			blockGrid.emplace_back(BlockCell {'T', 4, 1});
		} else if (position == 2){
			blockGrid.emplace_back(BlockCell {'T', 3, 1});
			blockGrid.emplace_back(BlockCell {'T', 4, 0});
			blockGrid.emplace_back(BlockCell {'T', 4, 1});
			blockGrid.emplace_back(BlockCell {'T', 4, 2});
		} else {
			blockGrid.emplace_back(BlockCell {'T', 2, 0});
			blockGrid.emplace_back(BlockCell {'T', 3, 0});
			blockGrid.emplace_back(BlockCell {'T', 3, 1});
			blockGrid.emplace_back(BlockCell {'T', 4, 0});
		}
	}
}

void Block::counter_clockwise() {
	clockwise();
	clockwise();
	clockwise();
}

int Block::getLevel() {
	return level;
}

int Block::numPieces() {
	return pieces;
}

void Block::decPieces() {
	--pieces;
}

BlockCell Block::getCell(int idx) const {
	return blockGrid[idx];
}
