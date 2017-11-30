#include "block.h"

using namespace std;

Block::~Block(){}

void Block::clockwiseRotate(){
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		if(blockGrid[idx].getInfo().type == BlockType::I){
			
			if(rotationVersion % 2 == 0){
				Cell newCell(middle->getInfo().row - blockGrid[idx].getInfo().col +  middle->getInfo().col, middle->getInfo().col, BlockType::I); 
				newCells.emplace_back(newCell);
			}
			else{
				Cell newCell( middle->getInfo().row, middle->getInfo().col - blockGrid[idx].getInfo().row +  middle->getInfo().row, BlockType::I);
				newCells.emplace_back(newCell);
			}
			
		}
		else if(blockGrid[idx].getInfo().type == BlockType::O){
			return;
		}
		else{
			int x = middle->getInfo().row - blockGrid[idx].getInfo().row;
			int y = middle->getInfo().col - blockGrid[idx].getInfo().col;
			int newRow = middle->getInfo().row;
			int newCol = middle->getInfo().col;
			if( x == 0 && y == 1){// middle left
				newRow = blockGrid[idx].getInfo().row - 1;
				newCol = blockGrid[idx].getInfo().col + 1;
			}
			else if( x == 0 && y == -1){// middle right
				newRow = blockGrid[idx].getInfo().row + 1;
				newCol = blockGrid[idx].getInfo().col - 1;
			}
			else if( x == 1 && y == 1){//top left
				newRow = blockGrid[idx].getInfo().row;
				newCol = blockGrid[idx].getInfo().col + 2;
			}
			else if( x == 1 && y == -1){//top right
				newRow = blockGrid[idx].getInfo().row + 2;
				newCol = blockGrid[idx].getInfo().col;
			}
			else if( x == 1 && y == 0){ //top middle
				newRow = blockGrid[idx].getInfo().row + 1;
				newCol = blockGrid[idx].getInfo().col + 1;
			}
			else if( x == -1 && y == 1){ // bottom left
				newRow = blockGrid[idx].getInfo().row - 2;
				newCol = blockGrid[idx].getInfo().col;
			}
			else if( x == -1 && y == 0){ // bottom middle
				newRow = blockGrid[idx].getInfo().row - 1;
				newCol = blockGrid[idx].getInfo().col - 1;
			}
			else if( x == -1 && y == -1){ // bottom right
				newRow = blockGrid[idx].getInfo().row;
				newCol = blockGrid[idx].getInfo().col - 2;
			}
			if(rotationVersion %4 == 1){
				newRow++;
			}
			if(rotationVersion %4 == 3){
				newRow++;
			}
			
			if(newRow < 0 || newRow > 17 || newCol < 0 || newCol > 10){
				return;
			}
			Cell newCell(newRow, newCol, blockGrid[idx].getInfo().type);
			newCells.emplace_back(newCell);
			
		}	
	}
	blockGrid.swap(newCells);
	rotationVersion++;
}


void Block::counterClockwiseRotate(){
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		if(blockGrid[idx].getInfo().type == BlockType::I){
			
			if(rotationVersion % 2 == 0){
				Cell newCell(middle->getInfo().row - blockGrid[idx].getInfo().col +  middle->getInfo().col, middle->getInfo().col, BlockType::I); 
				newCells.emplace_back(newCell);
			}
			else{
				Cell newCell( middle->getInfo().row, middle->getInfo().col - blockGrid[idx].getInfo().row +  middle->getInfo().row, BlockType::I);
				newCells.emplace_back(newCell);
			}
			
		}
		else if(blockGrid[idx].getInfo().type == BlockType::O){
			return;
		}
		else{
			int x = middle->getInfo().row - blockGrid[idx].getInfo().row;
			int y = middle->getInfo().col - blockGrid[idx].getInfo().col;
			int newRow = middle->getInfo().row;
			int newCol = middle->getInfo().col;
			if( x == 0 && y == 1){// middle left
				newRow = blockGrid[idx].getInfo().row + 1;
				newCol = blockGrid[idx].getInfo().col + 1;
			}
			else if( x == 0 && y == -1){// middle right
				newRow = blockGrid[idx].getInfo().row - 1;
				newCol = blockGrid[idx].getInfo().col - 1;
			}
			else if( x == 1 && y == 1){//top left
				newRow = blockGrid[idx].getInfo().row + 2;
				newCol = blockGrid[idx].getInfo().col;
			}
			else if( x == 1 && y == -1){//top right
				newRow = blockGrid[idx].getInfo().row;
				newCol = blockGrid[idx].getInfo().col - 2;
			}
			else if( x == 1 && y == 0){ //top middle
				newRow = blockGrid[idx].getInfo().row + 1;
				newCol = blockGrid[idx].getInfo().col - 1;
			}
			else if( x == -1 && y == 1){ // bottom left
				newRow = blockGrid[idx].getInfo().row;
				newCol = blockGrid[idx].getInfo().col + 2;
			}
			else if( x == -1 && y == 0){ // bottom middle
				newRow = blockGrid[idx].getInfo().row - 1;
				newCol = blockGrid[idx].getInfo().col + 1;
			}
			else if( x == -1 && y == -1){ // bottom right
				newRow = blockGrid[idx].getInfo().row - 2;
				newCol = blockGrid[idx].getInfo().col;
			}
			
			if(rotationVersion %4 == 2){
					newCol--;
			}
			if(rotationVersion %4 == 0){
				newCol--;
			}
			
			if(newRow < 0 || newRow > 17 || newCol < 0 || newCol > 10){
				return;
			}
			Cell newCell(newRow, newCol, blockGrid[idx].getInfo().type);
			newCells.emplace_back(newCell);
			
		}	
	}
	blockGrid.swap(newCells);
	rotationVersion--;
	if(rotationVersion < 0){
	 rotationVersion += 4;	
	}

}

int Block::getBlockLevel(){
	return blockLevel;
}

void Block::init(BlockType type, int level){
	blockGrid.clear();
	blockLevel = level;
	Cell *middleCell = new Cell(3,1);
	delete middle;
	middle = middleCell;
	if(type == BlockType::I){
		for(int i = 0; i < 4; i++){
			Cell newCell(3,i, BlockType::I);
			blockGrid.emplace_back(newCell);
		}
		delete middle;
		Cell *middleCell = new Cell(3, 0);
		middle = middleCell;
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
		rotationVersion = 2;
		Cell cell1(3,0, BlockType::T);
		Cell cell2(3,1, BlockType::T);
		Cell cell3(3,2, BlockType::T);
		Cell cell4(4,1, BlockType::T);
		blockGrid.emplace_back(cell1);
		blockGrid.emplace_back(cell2);
		blockGrid.emplace_back(cell3);
		blockGrid.emplace_back(cell4);
	}
	updateBlockRows();
}


void Block::updateBlockRows(){
     blockRows.clear();
      for(int i = 0; i <blockGrid.size(); i++){
	  if(findNum(blockRows, blockGrid[i].getInfo().row) == false){
		blockRows.emplace_back(blockGrid[i].getInfo().row);
	  }
	}
}

bool Block::findNum(vector<int> rows, int j){
	for(int i = 0; i <rows.size(); i++){
		if(i == j){
			return true;
		}
	}
	return false;
}

void Block::moveRight() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row, blockGrid[idx].getInfo().col+1, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
	Cell *newMiddle = new Cell(middle->getInfo().row, middle->getInfo().col+1);
	delete middle;
	middle = newMiddle;
}

void Block::moveLeft() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row, blockGrid[idx].getInfo().col-1, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
	Cell *newMiddle = new Cell(middle->getInfo().row, middle->getInfo().col-1);
	delete middle;
	middle = newMiddle;
}

void Block::moveDown() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row+1, blockGrid[idx].getInfo().col, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
	for(int i = 0; i < blockRows.size(); i++){
		blockRows[i]++;
	}
	Cell *newMiddle = new Cell(middle->getInfo().row+1, middle->getInfo().col);
	delete middle;
	middle = newMiddle;
}

void Block::moveUp() {
	vector<Cell> newCells;
	for (int idx = 0; idx < 4; idx++) {
		Cell newCell(blockGrid[idx].getInfo().row-1, blockGrid[idx].getInfo().col, blockGrid[idx].getInfo().type);
		newCells.emplace_back(newCell);
	}
	blockGrid.swap(newCells);
	for(int i = 0; i < blockRows.size(); i++){
		blockRows[i]--;
	}
	Cell *newMiddle = new Cell(middle->getInfo().row-1, middle->getInfo().col);
	delete middle;
	middle = newMiddle;
}

Info Block::cellInfo(int idx) {
	return blockGrid[idx].getInfo();
}

bool Block::canPlace(){
	return true;
}
