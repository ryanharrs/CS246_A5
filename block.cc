#include "block.h"

using namespace std;

Block::~Block{


}


void Block::clockwiseRotate(){
	vector<vector<Cell>> *newBlockGrid;
	int size = blockGrid->size() - 1;
	
	for(int j = 0; j < blockGrid[0]->size(); j++){
		vector<Cell> row;
		for(int i = blockGrid->size() - 1; i >= 0; i--){
			row.emplace_back(blockGrid[i][j]);
		}
		newBlockGrid->emplace_back(row);
	}
	delete theGrid;
	theGrid = newBlockGrid;
}


void Block::counterClockwiseRotate(){
	vector<vector<Cell>> *newBlockGrid;
	int size = blockGrid->size() - 1;
	
	for(int j = blockGrid[0]->size()-1; j>=0; j--){
		vector<Cell> row;
		for(int i = 0; i < blockGrid->size(); i++){
			row.emplace_back(blockGrid[i][j]);
		}
		newBlockGrid->emplace_back(row);
	}
	delete theGrid;
	theGrid = newBlockGrid;
	
}

void init(string blockType){
	delete blockGrid;
	vector<vector<Cell>> *newBlockGrid;
	if(blockType == "I"){
		vector<Cell> row;
		for(int i = 0; i < 4;){
			Cell newCell(0,i, 'I');
			row.emplace_back(newCell);
		}
		newBlockGrid->emplace_back(row);
	}
	if(blockType == "J"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1(0,0, 'J');
			Cell cell2(0,1);
			Cell cell3(0,2);
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4(1,0, 'J');
			Cell cell5(1,1, 'J');
			Cell cell6(1,2, 'J');
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
	}
	if(blockType == "L"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1(0,2, 'L');
			Cell cell2(0,1);
			Cell cell3(0,0);
			row1.emplace_back(cell3);
			row1.emplace_back(cell2);
			row1.emplace_back(cell1);
			Cell cell4(1,0, 'L');
			Cell cell5(1,1, 'L');
			Cell cell6(1,2, 'L');
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
	}
	if(blockType == "O"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1(0,0, 'O');
			Cell cell2(0,1, 'O');
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			Cell cell4(1,0, 'O');
			Cell cell5(1,1, 'O');
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
	}
	if(blockType == "S"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1(0,0);
			Cell cell2(0,1, 'S');
			Cell cell3(0,2, 'S');
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4(1,0, 'S');
			Cell cell5(1,1, 'S');
			Cell cell6(1,2);
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
	}
	if(blockType == "Z"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1(0,0, 'Z');
			Cell cell2(0,1, 'Z');
			Cell cell3(0,2);
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4(1,0);
			Cell cell5(1,1, 'J');
			Cell cell6(1,2, 'J');
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
	}
	if(blockType == "T"){
		vector<Cell> row1;
		vector<Cell> row2;
			Cell cell1(0,0, 'T');
			Cell cell2(0,1, 'T');
			Cell cell3(0,2, 'T');
			row1.emplace_back(cell1);
			row1.emplace_back(cell2);
			row1.emplace_back(cell3);
			Cell cell4(1,0);
			Cell cell5(1,1, 'J');
			Cell cell6(1,2);
			row2.emplace_back(cell4);
			row2.emplace_back(cell5);
			row2.emplace_back(cell6);
		newBlockGrid->emplace_back(row1);
		newBlockGrid->emplace_back(row2);
	}
	
	blockGrid = newBlockGrid;
}


bool Block::canPlace(){
	return true;
}