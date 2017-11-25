#include <iostream>
#include <string>
// You may include other allowed headers, as needed
//#include "board.h"
#include "state.h"
#include "graphicsdisplay.h"
#include <fstream>
#include <cstdlib>
#include <vector>
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

  bool random = 1;
//  Grid g;
  int level = 0;
  // Add code here
  vector <string> cmds ("left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "I", "J", "L", "restart", "hint");
  
  try {
  while (true) {

    //Getting a block b
    Block *b;
    if ((level==0)||!random){
        if(f >> block){
        	b = new Block(block);
	} else {
		break;
	}
    } else if (level==1){
	int r = rand() % 12 + 1;
	if (r==1){b = new Block("S"); }
	else if (r==2){b = new Block("Z");}
	else if ((r==3)||(r==4)) {b = new Block("T");}
	else if ((r==5)||(r==6)) {b = new Block("I");}
   	else if ((r==7)||(r==8)) {b = new Block("J"); }
	else if ((r==9)||(r==10)) {b = new Block("L");}
	else {b = new Block("O");}
    } else if (level==2){
	int r = rand() % 7 + 1;
        if (r==1) {b = new Block("S"); }
        else if (r==2) {b = new Block("Z");}
        else if (r==3) {b = new Block("T");}
        else if (r==4) {b = new Block("I");}
        else if (r==5) {b = new Block("J"); }
        else if (r==6) {b = new Block("L");}
        else {b = new Block("O");}
    } else {
        int r = rand() % 9 + 1;
        if ((r==1)||(r==2)){b = new Block("S"); }
        else if ((r==3)||(r==4)) {b = new Block("Z");}
        else if (r==5) {b = new Block("T");}
        else if (r==6) {b = new Block("I");}
        else if (r==7) {b = new Block("J"); }
        else if (r==8) {b = new Block("L");}
        else {b = new Block("O");}
    }
    //Figuring out which command was entered
    cin >> cmd;
    vector<string> temp = cmds;
    int temp2 = temp.size();
    for (int i = 0; i<cmd.length(); i++){
	for (int j = 0; j<temp.size(); j++){
		if ((temp[j][i]!=cmd[i])&&(temp[j]!="Nah")){
			temp[j] = "Nah";
			temp2--;
		}
	}
    }
    for (int i = 0; i<temp.size(); i++){
	if (temp[i]!="Nah"){
		cmd = temp[i];
	}
    }
    if (temp2!=1){
	cerr << "Enter a valid command" << endl;
    }
    else if (cmd == "restart") {
	//g.init(n);
	//cout<<g;
    }
    else if (cmd == "left") {
	cout << cmd;
    } else if (cmd == "right"){

    } else if (cmd == "down"){

    }
    else if (cmd == "levelup"){
	if (level!=4){
	    level++;
	}
    } else if (cmd == "leveldown"){
	if (level!=0){
		level--;
	}
    }
    else if (cmd == "norandom"){
	cin >> cmd;
	f {cmd};
	random = 0;
    } else if (cmd == "random"){
	random = 1;
    }
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}
