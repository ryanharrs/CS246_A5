#include "textdisplay.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay() {
	theDisplay.clear();
	for(int row = 0; row < 18; row++){
		vector<char>newRow;
		for(int column = 0; column < 11; column++){
				newRow.emplace_back(' ');
		}
		theDisplay.emplace_back(newRow);
	}
}

void TextDisplay::notify(Subject<Info> &whoNotified){
	if (whoNotified.getInfo().type == ' ') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = ' ';
	} else if (whoNotified.getInfo().type == 'I') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'I';
	} else if (whoNotified.getInfo().type == 'J') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'J';
	} else if (whoNotified.getInfo().type == 'L') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'L';
	} else if (whoNotified.getInfo().type == 'O') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'O';
	} else if (whoNotified.getInfo().type == 'S') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'S';
	} else if (whoNotified.getInfo().type == 'Z') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'Z';
	} else if (whoNotified.getInfo().type == 'T') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = 'T';
	} else if (whoNotified.getInfo().type == '*') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = '*';
	} else if (whoNotified.getInfo().type == '?') {
		theDisplay[whoNotified.getInfo().row][whoNotified.getInfo().col] = '?';
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
