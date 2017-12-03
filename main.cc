#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "board.h"
#include "block.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {

  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  //srand(time(NULL));
  string block;
  int level = 0;
  
  //string file = argv[1];
  //ifstream f {file};
  

  bool random = 1;
  Board gameBoard;
  gameBoard.init();

  vector <string> cmds; 
  string a [16]= {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "I", "J", "L", "restart", "hint"};
  for (int i = 0; i<16; i++){
  cmds.push_back(a[i]);
  }
  
  try {
    while (true) {
      int curr_row = 0, curr_col = 0;
      //Figuring out which command was entered
      cout << "Enter a command: ";
      cin >> cmd;
      cout << endl;
      vector<string> temp = cmds;
      int temp2 = temp.size();
      for (unsigned i = 0; i<cmd.length(); i++){
          for (unsigned j = 0; j<temp.size(); j++){
                  if ((temp[j][i]!=cmd[i])&&(temp[j]!="Nah")){
                          temp[j] = "Nah";
                          temp2--;
                  }
          }
      }
      for (unsigned i = 0; i<temp.size(); i++){
          if (temp[i]!="Nah"){
                  cmd = temp[i];
          }
      }
      if (temp2!=1){
          cerr << "Enter a valid command" << endl;
      }
      //Commands that don't need a block
      if (cmd=="restart"){
          //g.init(n);
          //cout<<g;
      } else if (cmd == "levelup"){
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
          ifstream f {cmd};
          random = 0;
      } else if (cmd == "random"){
          random = 1;
      } else if (cmd == "play") {}
      //Getting a block b
      Block *b;
      if ((level==0)||!random){
          //if(f >> block){
           // b.init(block);
          //}
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
      if (gameBoard.canPlace(curr_row, curr_col, *b)) {
        gameBoard.setPiece(curr_row, curr_col, *b);
        cout << "Level:" << setw(7) << level << endl;
        cout << gameBoard << endl;
      } else {
        cout << "You Lose" << endl;
        break;
      }
      cout << "Enter move: ";
      cin >> cmd;
      cout << endl;
    //"Play" Commands (in the game - require a new block)
	bool hintPlaced = false;
      while (cmd != "drop") {
	
        gameBoard.clearPiece(curr_row, curr_col, *b);
        if (cmd == "left") {
          --curr_col;
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            ++curr_col;
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "hint"){
		Block *hintBlock = new Block{b.type, level, true};          
		hintPlaced = true;

          }
        } else if (cmd == "right"){
          ++curr_col;
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            --curr_col;
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "clockwise"){
          b->clockwise();
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            b->counter_clockwise();
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "counterclockwise"){
          b->counter_clockwise();
          if (gameBoard.canPlace(curr_row, curr_col, *b)) {
            gameBoard.setPiece(curr_row, curr_col, *b);
          } else {
            b->clockwise();
            gameBoard.setPiece(curr_row, curr_col, *b);
          }
        } else if (cmd == "drop"){
          break;
        }
        cout << "Level:" << setw(7) << level << endl;
        cout << gameBoard << endl;
        cout << "Enter move: ";
        cin >> cmd;
        cout << endl;
      }
      gameBoard.clearPiece(curr_row, curr_col, *b);
	if(hintPlaced == true){
      		gameBoard.clearPiece(hint_row, hint_col, *hintBlock);
	}
      while (gameBoard.canPlace(curr_row, curr_col, *b)) ++curr_row;
      --curr_row;
      gameBoard.setPiece(curr_row, curr_col, *b);
      gameBoard.clearRows(level);
      cout << "Level:" << setw(7) << level << endl;
      cout << gameBoard << endl;
    }
  } catch (ios::failure &) {}  // Any I/O failure quits
}