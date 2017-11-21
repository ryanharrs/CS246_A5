#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "grid.h"
#include "state.h"
#include "graphicsdisplay.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;

  // Add code here
  char turn = 'B';

  try {
  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      // Add code here
	g.init(n);
	cout<<g;
	
    }
    else if (cmd == "play") {
      int r = 0, c = 0;
      cin >> r >> c;
	if(turn == 'B'){	
  		g.setPiece(r, c, Colour::Black);
		turn = 'W';
	}
	else{
		g.setPiece(r, c, Colour::White);
		turn = 'B';
	}
	if(g.isFull() == true){
		if(g.whoWon() == Colour::Black){
			cout<<"Black Wins!"<<endl;
		}
		else if(g.whoWon() == Colour::White){
			cout<<"White Wins!"<<endl;
		}
		else{
			cout<<"Tie!"<<endl;
		}			
	}
	cout<<g;
		
    }
	
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}
