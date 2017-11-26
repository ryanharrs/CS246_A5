#include "block.h"

using namespace std;

Block::~Block(){}

void Block::clockwiseRotate(){
}


void Block::counterClockwiseRotate(){
}

void Block::init(BlockType type){
	blockGrid.clear();
	if(type == BlockType::I){
		for(int i = 0; i < 4;){
			Cell newCell(3,i, BlockType::I);
			blockGrid.emplace_back(newCell);
		}
	}
	if(type == BlockType::J){
		Cell cell1(3,0, BlockType::J);
		Cell cell2(4,0, BlockType::J);
		Cell cell3(4,1, BlockType::J);
		Cell cell4(4,2, BlockType::J);
		blockGrid.emplace_back(cell1);
		blockGrid.emplace_back(cell2);
		blockGrid.emplace_back(cell3);
		blockGrid.emplace_back(cell4);
	}
	if(type == BlockType::L){
		Cell cell1(3,2, BlockType::L);
		Cell cell2(4,0, BlockType::L);
		Cell cell3(4,1, BlockType::L);
		Cell cell4(4,2, BlockType::L);
		blockGrid.emplace_back(cell1);
		blockGrid.emplace_back(cell2);
		blockGrid.emplace_back(cell3);
		blockGrid.emplace_back(cell4);
	}
	if(type == BlockType::O){
		Cell cell1(3,0, BlockType::O);
		Cell cell2(3,1, BlockType::O);
		Cell cell3(4,0, BlockType::O);
		Cell cell4(4,1, BlockType::O);
		blockGrid.emplace_back(cell1);
		blockGrid.emplace_back(cell2);
		blockGrid.emplace_back(cell3);
		blockGrid.emplace_back(cell4);
	}
	if(type == BlockType::S){
		Cell cell1(3,1, BlockType::S);
		Cell cell2(3,2, BlockType::S);
		Cell cell3(4,0, BlockType::S);
		Cell cell4(4,1, BlockType::S);
		blockGrid.emplace_back(cell1);
		blockGrid.emplace_back(cell2);
		blockGrid.emplace_back(cell3);
		blockGrid.emplace_back(cell4);
	}
	if(type == BlockType::Z){
		Cell cell1(3,0, BlockType::Z);
		Cell cell2(3,1, BlockType::Z);
		Cell cell3(4,1, BlockType::Z);
		Cell cell4(4,2, BlockType::Z);
		blockGrid.emplace_back(cell1);
		blockGrid.emplace_back(cell2);
		blockGrid.emplace_back(cell3);
		blockGrid.emplace_back(cell4);
	}
	if(type == BlockType::T){
		Cell cell1(3,0, BlockType::T);
		Cell cell2(3,1, BlockType::T);
		Cell cell3(3,2, BlockType::T);
		Cell cell4(4,1, BlockType::T);
		blockGrid.emplace_back(cell1);
		blockGrid.emplace_back(cell2);
		blockGrid.emplace_back(cell3);
		blockGrid.emplace_back(cell4);
	}
}

void Block::moveRight() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row, blockGrid[idx].getInfo().col+1, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
}

void Block::moveLeft() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row, blockGrid[idx].getInfo().col-1, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
}

void Block::moveDown() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row+1, blockGrid[idx].getInfo().col, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
}

void Block::moveUp() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row-1, blockGrid[idx].getInfo().col, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
}

Info Block::cellInfo(int idx) {
	return blockGrid[idx].getInfo();
}

bool Block::canPlace(){
	return true;
}
