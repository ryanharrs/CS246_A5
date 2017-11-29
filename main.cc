#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "board.h"
#include "state.h"
#include "graphicsdisplay.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include "block.h"
#include <ctime>
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {

  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  void srand(int seed);
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
      Block b;
      if ((level==0)||!random){
          //if(f >> block){
           // b.init(block);
          //}
      } else if (level==1){
        int r = rand() % 12 + 1;
        if (r==1){b.init(BlockType::S, level); }
        else if (r==2){b.init(BlockType::Z, level);}
        else if ((r==3)||(r==4)) {b.init(BlockType::T, level);}
        else if ((r==5)||(r==6)) {b.init(BlockType::I, level);}
        else if ((r==7)||(r==8)) {b.init(BlockType::J, level);}
        else if ((r==9)||(r==10)) {b.init(BlockType::L, level);}
        else {b.init(BlockType::O, level);}
      } else if (level==2){
      int r = rand() % 7 + 1;
        if (r==1) {b.init(BlockType::S, level); }
        else if (r==2) {b.init(BlockType::Z, level);}
        else if (r==3) {b.init(BlockType::T, level);}
        else if (r==4) {b.init(BlockType::I, level);}
        else if (r==5) {b.init(BlockType::J, level); }
        else if (r==6) {b.init(BlockType::L, level);}
        else {b.init(BlockType::O, level);}
      } else {
        int r = rand() % 9 + 1;
        if ((r==1)||(r==2)){b.init(BlockType::S, level); }
        else if ((r==3)||(r==4)) {b.init(BlockType::Z, level);}
        else if (r==5) {b.init(BlockType::T, level);}
        else if (r==6) {b.init(BlockType::I, level);}
        else if (r==7) {b.init(BlockType::J, level); }
        else if (r==8) {b.init(BlockType::L, level);}
        else {b.init(BlockType::O, level);}
      }
      cout << level << endl;
      if (gameBoard.isEmpty(b)) {
        gameBoard.newBlock(b);
        cout << gameBoard << endl;
      } else {
        cout << "You Lose" << endl;
        break;
      }
      cout << "Enter move: ";
      cin >> cmd;
      cout << endl;
    //"Play" Commands (in the game - require a new block)
      while (cmd != "drop") {
        gameBoard.clearBlock(b);
        if (cmd == "left") {
          b.moveLeft();
          if (gameBoard.isEmpty(b)) {
            gameBoard.newBlock(b);
          } else {
            b.moveRight();
            gameBoard.newBlock(b);
          }
          cout << cmd << endl;
        } else if (cmd == "right"){
          b.moveRight();
          if (gameBoard.isEmpty(b)) {
            gameBoard.newBlock(b);
         } else {
            b.moveLeft();
            gameBoard.newBlock(b);
          }
          cout << cmd << endl;
        } else if (cmd == "down"){
          b.moveDown();
          if (gameBoard.isEmpty(b)) {
            gameBoard.newBlock(b);
         } else {
            b.moveUp();
            gameBoard.newBlock(b);
          }
          cout << cmd << endl;
       }else if (cmd == "clockwise"){
	          b.clockwiseRotate();
          if (gameBoard.isEmpty(b)) {
            gameBoard.newBlock(b);
         } else {
            b.moveUp();
            gameBoard.newBlock(b);
          }
          cout << cmd << endl;
        } else if (cmd == "counterclockwise"){
	        b.counterClockwiseRotate();
          if (gameBoard.isEmpty(b)) {
            gameBoard.newBlock(b);
         } else {
            b.moveUp();
            gameBoard.newBlock(b);
          }

          cout << cmd << endl;
        } else if (cmd == "drop"){
    	  cout<<"youre a wizard harry"<<endl;
          break;
          cout << cmd << endl;
        }
        cout << gameBoard << endl;
        cout << "Enter move: ";
        cin >> cmd;
        cout << endl;
      }
      gameBoard.clearBlock(b);
      gameBoard.dropBlock(b, level);
      cout << gameBoard << endl;
      cout<<gameBoard.getCurrScore()<<endl;
    }
  } catch (ios::failure &) {}  // Any I/O failure quits
}