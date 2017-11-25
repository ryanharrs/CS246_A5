#include "textdisplay.h"
#include <iostream>
#include "observer.h"
#include "state.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay() {
	theDisplay.clear();
	for(int row = 0; row < 15; row++){
		vector<char>theRow;
		for(int column = 0; column < 11; column++){
				newRow.emplace_back(' ');
		}
		theDisplay.emplace_back(newRow);
	}
}

void TextDisplay::notify(Subject<Info, State> &whoNotified){
	Info currInfo = whoNotified.getInfo();
	theDisplay[currInfo.row][currInfo.col] = currInfo.blockType;

}

ostream &operator<<(ostream &out, const TextDisplay &td){
	out << "-----------" << endl;
	for(int  = 0; i < td.gridSize; i ++){
		for(int j = 0 ;j < td.gridSize; j++){
			cout<<td.theDisplay[i][j];
		}
		cout<<endl;
	}
	out << "-----------" << endl;
	return out;	
}
