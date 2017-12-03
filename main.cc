#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "board.h"
#include "block.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// Do not remove any code; do not add code other than where indicated.

string commandFinder(string cmd){
  vector <string> cmds;
  string a [21]= {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "I", "J", "L", "O", "S", "Z", "T","restart", "hint", "play"};
  for (int i = 0; i<21; i++){
  cmds.push_back(a[i]);
  }
      string cmd2 = cmd;
      vector<string> temp = cmds;
      int temp2 = temp.size();
      for (unsigned i = 0; i<cmd2.length(); i++){
          for (unsigned j = 0; j<temp.size(); j++){
                  if ((temp[j][i]!=cmd2[i])&&(temp[j]!="Nah")){
                          temp[j] = "Nah";
                          temp2--;
                  }
          }
      }
      for (unsigned i = 0; i<temp.size(); i++){
          if (temp[i]!="Nah"){
                  cmd2 = temp[i];
          }
      }
      if (temp2!=1){
          return "bad command";
      }
     return cmd2;
}

Block *getblock(string block, int level, bool random){
        Block *b;
	if (level==0||random==0){
            if (block=="T"){b = new Block {'T', level};}
            else if (block=="S"){b = new Block {'S', level};}
            else if (block=="Z"){b = new Block {'Z', level};}
            else if (block=="O"){b = new Block {'O', level};}
            else if (block=="J"){b = new Block {'J', level};}
            else if (block=="L"){b = new Block {'L', level};}
            else if (block=="I"){b = new Block {'I', level};}
         
      } else if (level==1){
        int r = rand() % 12 + 1;
        if (r==1){ b = new Block {'S', level}; }
        else if (r==2) { b = new Block {'Z', level};}
        else if ((r==3)||(r==4)) { b = new Block {'T', level};}
        else if ((r==5)||(r==6)) { b = new Block {'I', level};}
        else if ((r==7)||(r==8)) { b = new Block {'J', level};}
        else if ((r==9)||(r==10)) { b = new Block {'L', level};}
        else { b = new Block {'O', level}; }
      } else if (level==2){
      int r = rand() % 7 + 1;
        if (r==1) { b = new Block {'S', level}; }
        else if (r==2) { b = new Block {'Z', level};}
        else if (r==3) { b = new Block {'T', level};}
        else if (r==4) { b = new Block {'I', level};}
        else if (r==5) { b = new Block {'J', level};}
        else if (r==6) { b = new Block {'L', level};}
        else { b = new Block {'O', level}; }
      } else {
        int r = rand() % 9 + 1;
        if ((r==1)||(r==2)) { b = new Block {'S', level}; }
        else if ((r==3)||(r==4)) { b = new Block {'Z', level};}
        else if (r==5) { b = new Block {'T', level};}
        else if (r==6) { b = new Block {'I', level};}
        else if (r==7) { b = new Block {'J', level};}
        else if (r==8) { b = new Block {'L', level};}
        else { b = new Block {'O', level}; }
      }
      return b;
}

void printBlock(char t){
	if (t=='T'){ cout << " T " << endl << "TTT" << endl;}
	else if (t=='S'){ cout << " SS" << endl << "SS " << endl;}
        else if (t=='Z'){ cout << "ZZ " << endl << " ZZ" << endl;}
        else if (t=='O'){ cout << "OO" << endl << "OO" << endl;}
        else if (t=='L'){ cout << "  L" << endl << "LLL" << endl;}
        else if (t=='J'){ cout << "J  " << endl << "JJJ" << endl;}
        else if (t=='I'){ cout << "IIII" << endl;}
}

int main(int argc, char *argv[]) {

  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  //srand(time(NULL));
  string block;
  int level = 0;
  
  bool newblock = 1;
  bool random = 1;
  Board gameBoard;
  gameBoard.init();
int curr_row = 0, curr_col = 0;
  int counter = 0;
  bool first=1;
  int done = 2;
  
  ifstream f{argv[1]};
  
  string s;	//name of initial file
  string s2;	//name of non random file
  f>>s;
  Block *b = getblock(s, level, random); 
  Block *next;

  vector <string> cmds2;	//cmds from norandom
  vector <string> cmds3;
  try {
    while (done!=0) {
    //Getting a block b
      if (newblock==1&&done!=0){
        if (first!=1){
	   b = next;
	}
	first = 0;
	curr_row = 0;
        curr_col = 0;
      	string str;
      if (level==0){
        if(!(f>>str)) done--;
      } else if (random == 0){
        if (!cmds2.empty()){
	    str = cmds2.back();
	    cmds2.pop_back();
	} else {
	    cout << "No more commands" << endl;
	    done--;
	}
      } else {
          str = "";
      }
      if (done>1){
      next = getblock(str, level, random);
	}
  
	//If new block can be placed
     if (gameBoard.canPlace(curr_row, curr_col, *b)) {
        gameBoard.setPiece(curr_row, curr_col, *b);
        cout << "Level:" << setw(7) << level << endl;
        cout << gameBoard << endl;
        cout << "Next: " << endl;
        if (done>1) {printBlock(next->getCell(0).type);
	} else { cout << endl << endl;}
      } else {
        cout << "You Lose" << endl;
        break;
      }
      }
      newblock = 0; 
      //Figuring out which command was entered
      if (counter==0&&cmds3.size()==0){
          cout << "Enter a command: ";
          cin >> cmd;
          string tempstr = cmd;
          int tempint;
          istringstream iss(tempstr);
          if (iss >> tempint){
	      counter = tempint-1;
              cmd = cmd.substr(tempint/10 + 1, cmd.length()-1);
              if (cmd=="restart"||cmd=="hint"||cmd=="norandom"||cmd=="hint"){
		  counter = 0;
      	      }
          }
      cmd = commandFinder(cmd);
      } else if (cmds3.size()!=0){
	cmd = cmds3.back();
	cmds3.pop_back();
	cmd = commandFinder(cmd);
      } else {
         counter --;
      }
      //Commands that don't need a block
      if (cmd=="restart"){
          //g.init(n);
          //cout<<g;
      } else if (cmd == "levelup"){
          if (level!=4){
              level++;
	      random = 1;
          }
      } else if (cmd == "leveldown"){
          if (level!=0){
                  level--;
          }
      }
      else if (cmd == "norandom"){
	  string tt;
	  cin >> tt;
	  ifstream f2{tt};
          while(f2>>tt){
		cmds2.insert(cmds2.begin(), tt);
          }
          random = 0;
      } else if (cmd == "random"){
          random = 1;
      } else if (cmd == "sequence"){
          string tt;
          cin >> tt;
          ifstream f2{tt};
          while(f2>>tt){
                cmds3.insert(cmds3.begin(), tt);
          }
     } else  if (cmd == "left") {
          gameBoard.clearPiece(curr_row, curr_col, *b);
          --curr_col;
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            ++curr_col;
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "right"){
	gameBoard.clearPiece(curr_row, curr_col, *b);
          ++curr_col;
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            --curr_col;
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "down"){
        gameBoard.clearPiece(curr_row, curr_col, *b);
          ++curr_row;
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            --curr_row;
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "clockwise"){
	gameBoard.clearPiece(curr_row, curr_col, *b);
          b->clockwise();
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            b->counter_clockwise();
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "counterclockwise"){
	gameBoard.clearPiece(curr_row, curr_col, *b);
          b->counter_clockwise();
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            b->clockwise();
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "drop"){
             gameBoard.clearPiece(curr_row, curr_col, *b);
             while (gameBoard.canPlace(curr_row, curr_col, *b)) ++curr_row;
             --curr_row;
             gameBoard.setPiece(curr_row, curr_col, *b);
             gameBoard.clearRows(level);
             newblock = 1;
	} else if (cmd=="I"||cmd=="J"||cmd=="L"||cmd=="S"||cmd=="Z"||cmd=="T"||cmd=="O"){
		Block *tempb = b;
		b = getblock(cmd, level, random);
		delete tempb;
        } else if (cmd=="hint"){

	}

       if (newblock==0){
        cout << "Level:" << setw(7) << level << endl;
        cout << gameBoard << endl;
        cout << "Next: " << endl;
	printBlock(next->getCell(0).type);
      }
      if (done==0) break;
      //gameBoard.clearPiece(curr_row, curr_col, *b);
      //while (gameBoard.canPlace(curr_row, curr_col, *b)) ++curr_row;
      //--curr_row;
      //gameBoard.setPiece(curr_row, curr_col, *b);
      //gameBoard.clearRows(level);
      //cout << "Level:" << setw(7) << level << endl;
     // cout << gameBoard << endl;
    }
  } catch (ios::failure &) {}  // Any I/O failure quits
}
