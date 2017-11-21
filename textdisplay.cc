#include "textdisplay.h"
#include <iostream>
#include "observer.h"
#include "state.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n}{
	int x = n/2 - 1;
	for(int i = 0; i < n; i++){
		vector<char>newRow;
		for(int j = 0; j < n; j++){
			if(( i == x && j == x) || (i == x + 1 && j == x +1)){
				newRow.emplace_back('B');
			}
			else if((i == x && j == x + 1) || (i == x + 1 && j == x)){
				newRow.emplace_back('W');
			}
			else{
				newRow.emplace_back('-');
			}
		}
		theDisplay.emplace_back(newRow);
	}
}

void TextDisplay::notify(Subject<Info, State> &whoNotified){
	Info currInfo = whoNotified.getInfo();
	char newChar = '-';
	if(currInfo.colour == Colour::Black){
		newChar = 'B';
	}
	if(currInfo.colour == Colour::White){
		newChar = 'W';
	}
	theDisplay[currInfo.row][currInfo.col] = newChar;
}

ostream &operator<<(ostream &out, const TextDisplay &td){
	for(int i = 0; i < td.gridSize; i ++){
		for(int j = 0 ;j < td.gridSize; j++){
			cout<<td.theDisplay[i][j];
		}
		cout<<endl;
	}
	return out;	
}
