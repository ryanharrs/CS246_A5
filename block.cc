#include "block.h"

using namespace std;

Block::~Block(){

}

void Block::clockwiseRotate(){
	vector<vector<Cell>> *newBlockGrid;
	int size = blockGrid->size() - 1;
	
	for(int j = 0; j < blockGrid[0].size(); j++){
		vector<Cell> row;
		for(int i =size; i >= 0; i--){
			row.emplace_back(blockGrid[i][j]);
		}
		newBlockGrid->emplace_back(row);
	}
	delete blockGrid;
	blockGrid = newBlockGrid;
	int tempWidth = width;
	width = height;	
	height = tempWidth;
	notifyObservers();
}


void Block::counterClockwiseRotate(){
	vector<vector<Cell>> *newBlockGrid;
	int size = blockGrid->size() - 1;
	
	for(int j = size; j>=0; j--){
		vector<Cell> row;
		for(int i = 0; i < blockGrid->size(); i++){
			row.emplace_back(blockGrid[i][j]);
		}
		newBlockGrid->emplace_back(row);
	}
	delete blockGrid;
	blockGrid = newBlockGrid;
	int tempWidth = width;
	width = height;	
	height = tempWidth;
	notifyObservers();
}

void Block::init(string blockType){
	x = 0;
	y = 3;
	delete blockGrid;
	vector<vector<Cell>> *newBlockGrid;
	if(blockType == "I"){
		vector<Cell> row;
		for(int i = 0; i < 4;){
			Cell newCell(0,i, 'I');
			row.emplace_back(newCell);
		}
		newBlockGrid->emplace_back(row);
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
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
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
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
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
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
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
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
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
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
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
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
		height = 2;
		width = 3;
	}
	
	blockGrid = newBlockGrid;
}


bool Block::canPlace(){
	return true;
}