#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "board.h"
#include "state.h"
#include "graphicsdisplay.h"
#include <fstream>
#include <cstdlib>
using namespace std;

// Do not remove any code; do not add code other than where indicated.

class Block{
	public:
	string s;
	Block(string s = ""): s{s} {}
};
int main(int argc, char *argv[]) {

  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;

  string block;
  string file = argv[1];
  ifstream f {file};
//  Grid g;
  int level = 0;
  // Add code here

  try {
  while (true) {
    Block *b;
    if (level==0){
        if(f >> block){
        	b = new Block(block);
	} else {
		break;
	}
    } else if (level==1){
	int r = rand() % 12 + 1;
	if (r==1){ }
	else if (r==2){ }
	else if ((r==3)||(r==4)) { }
	else if ((r==5)||(r==6)) { }
   	else if ((r==7)||(r==8)) { }
	else if ((r==9)||(r==10)) { }
	else {}
    } else if (level==2){

    } else {

    }
    cin >> cmd;
    if (cmd == "restart") {
	//g.init(n);
	//cout<<g;
    }
    else if (cmd == "left") {
	cout << b->s << endl;;	
    }
    else if (cmd == "levelup"){
	if (level!=4){
	    level++;
	}
    }
	
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}
