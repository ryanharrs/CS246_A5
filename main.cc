#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "grid.h"
#include "state.h"
#include "graphicsdisplay.h"
#include <fstream>
using namespace std;

// Do not remove any code; do not add code other than where indicated.

class Block{
	public:
	string s;
}
int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;

  // Add code here

  try {
  while (true) {
    if (level==1){
	ifstream f = {argv[1]};
	Block *b = getBlock(f);
    } else {
	Block *b = getBlock(level);
    }
    cin >> cmd;
    if (cmd == "restart") {
	//g.init(n);
	//cout<<g;
    }
    else if (cmd == "left") {
		
    }
	
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}

Block *getBlock(ifstream f){
        string block;
        f >> block;
        Block *b = new Block(block);
        return b;
}
Block *getBlock(int level){
	if (level==2){

	} else {

	}
}
