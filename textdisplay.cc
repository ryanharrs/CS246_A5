#include "textdisplay.h"
#include <iostream>
#include "observer.h"
#include "state.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay():gridSize{18} {
	theDisplay.clear();
	for(int row = 0; row < 18; row++){
		vector<char>newRow;
		for(int column = 0; column < 11; column++){
				newRow.emplace_back(' ');
		}
		theDisplay.emplace_back(newRow);
	}
}

void TextDisplay::notify(Subject<Info, State> &whoNotified){
	if (whoNotified.getInfo().type == BlockType::None) {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = ' ';
	} else if (whoNotified.getInfo().type == BlockType::I) {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'I';
	} else if (whoNotified.getInfo().type == BlockType::J) {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'J';
	} else if (whoNotified.getInfo().type == BlockType::L) {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'L';
	} else if (whoNotified.getInfo().type == BlockType::O) {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'O';
	} else if (whoNotified.getInfo().type == BlockType::S) {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'S';
	} else if (whoNotified.getInfo().type == BlockType::Z) {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'Z';
	} else {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'T';
	}
}

ostream &operator<<(ostream &out, const TextDisplay &td){
	out << "-----------" << endl;
	for(int row = 0; row < 18 ; row++){
		for(int column = 0 ; column < 11; column++){
			cout<<td.theDisplay[row][column];
		}
		cout<<endl;
	}
	out << "-----------";
	return out;	
}
