#include "block.h"

using namespace std;

Block::~Block(){

}

void Block::clockwiseRotate(){
	}

Info Block::getInfo()const{
	Info thisInfo{0,0, Colour::None, blockType[0]};
	return thisInfo;	
}

void Block::counterClockwiseRotate(){
	
}

void Block::init(string bt){
	x = 0;
	y = 3;
	blockType = bt;
	blockGrid.clear();
	if(blockType == "I"){
		vector<Cell> row;
		for(int i = 0; i < 4;){
			Cell newCell{0,i, 'I'};
			row.emplace_back(newCell);
		}
		blockGrid.emplace_back(row);
		height = 1;
		width = 4;
	}
	if(blockType == "J"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1{0,3, 'J'};
			Cell cell2{0,4};
			Cell cell3{0,5};
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4{1,3, 'J'};
			Cell cell5{1,4, 'J'};
			Cell cell6{1,5, 'J'};
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		blockGrid.emplace_back(row1);
		blockGrid.emplace_back(row2);
		height = 2;
		width = 3;
	}
	if(blockType == "L"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1{0,5, 'L'};
			Cell cell2{0,4};
			Cell cell3{0,3};
			row1.emplace_back(cell3);
			row1.emplace_back(cell2);
			row1.emplace_back(cell1);
			Cell cell4{1,3, 'L'};
			Cell cell5{1,4, 'L'};
			Cell cell6{1,5, 'L'};
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		blockGrid.emplace_back(row1);
		blockGrid.emplace_back(row2);
		height = 2;
		width = 3;
	}
	if(blockType == "O"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1{0,3, 'O'};
			Cell cell2{0,4, 'O'};
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			Cell cell4{1,3, 'O'};
			Cell cell5{1,4, 'O'};
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
		blockGrid.emplace_back(row1);
		blockGrid.emplace_back(row2);
		height = 2;
		width = 2;
	}
	if(blockType == "S"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1{0,3};
			Cell cell2{0,4, 'S'};
			Cell cell3{0,5, 'S'};
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4{1,3, 'S'};
			Cell cell5{1,4, 'S'};
			Cell cell6{1,5};
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		blockGrid.emplace_back(row1);
		blockGrid.emplace_back(row2);
		height = 2;
		width = 3;
	}
	if(blockType == "Z"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1{0,3, 'Z'};
			Cell cell2{0,4, 'Z'};
			Cell cell3{0,5};
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4{1,3};
			Cell cell5{1,4, 'J'};
			Cell cell6{1,5, 'J'};
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		blockGrid.emplace_back(row1);
		blockGrid.emplace_back(row2);
		height = 2;
		width = 3;
	}
	if(blockType == "T"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1{0,3, 'T'};
			Cell cell2{0,4, 'T'};
			Cell cell3{0,5, 'T'};
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4{1,3};
			Cell cell5{1,4, 'J'};
			Cell cell6{1,5};
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		blockGrid.emplace_back(row1);
		blockGrid.emplace_back(row2);
		height = 2;
		width = 3;
	}
	
	}


bool Block::canPlace(){
	return true;
}