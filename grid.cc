#include "grid.h"
#include <iostream>
#include <vector>
#include <cstddef>
#undef None
using namespace std;

Grid::~Grid(){
	delete td;
	delete gd;
	delete ob;
}

void Grid::setObserver(Observer<Info, State> *setob){
	delete ob;
	ob = setob;
}

bool Grid::isFull() const{
	int n = theGrid.size();
	for(int i = 0; i <n; i++){
		for(int j = 0; j < n; j++){
			if(theGrid[i][j].getInfo().colour == Colour::None){
				return false;
			}
		}
	}
	return true;
}


Colour Grid::whoWon() const{
	int numWhite = 0;
	int numBlack = 0;;
	int n = theGrid.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(theGrid[i][j].getInfo().colour == Colour::Black){
				numBlack++;
			}
			else{
				numWhite++;
			}
		}
	}

	if(numBlack > numWhite){
		return Colour::Black;
	}
	if(numBlack < numWhite){
		return Colour::White;
	}
	return Colour::None;

}


void Grid::init(size_t n){
	int x = n;
	delete td;
	delete gd;
	theGrid.clear();
	td = new TextDisplay(x);
	gd = new GraphicsDisplay(x, 500);
	for(int i = 0; i < x; i++){
		vector<Cell>newRow;
		for (int j =0; j < x; j++){
			Cell newCell(i,j);
			newCell.attach(td);
			newCell.attach(gd);
			newRow.emplace_back(newCell);
		}
		theGrid.emplace_back(newRow);	
	}
}

void Grid::setPiece(size_t r, size_t c, Colour colour){
	theGrid[r][c].setPiece(colour);
	
}

void Grid::toggle(size_t r, size_t c){
	theGrid[r][c].toggle();
}




std::ostream &operator<<(std::ostream &out, const Grid &g){
	cout<<*g.td;
	return out;
}



