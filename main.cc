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

shared_ptr<Block> getblock(string block, int level, bool random){
      std::shared_ptr<Block> b;
      if (level==0||random==0){
        if (block=="T"){ b = make_shared<Block>('T',level); }
        else if (block=="S"){b = make_shared<Block>('S',level);}
        else if (block=="Z"){ b = make_shared<Block>('Z',level);}
        else if (block=="O"){b = make_shared<Block>('O',level);}
        else if (block=="J"){b = make_shared<Block>('J',level);}
        else if (block=="L"){b = make_shared<Block>('L',level);}
        else if (block=="I"){ b = make_shared<Block>('I',level);}
      } else if (level==1){
        int r = rand() % 12 + 1;
        if (r==1){ b = make_shared<Block>('S',level); }
        else if (r==2) { b = make_shared<Block>('Z',level);}
        else if ((r==3)||(r==4)) { b = make_shared<Block>('T',level);}
        else if ((r==5)||(r==6)) { b = make_shared<Block>('I',level);}
        else if ((r==7)||(r==8)) { b = make_shared<Block>('J',level);}
        else if ((r==9)||(r==10)) { b = make_shared<Block>('L',level);}
        else { b = make_shared<Block>('O',level); }
      } else if (level==2){
      int r = rand() % 7 + 1;
        if (r==1) { b = make_shared<Block>('S',level); }
        else if (r==2) { b = make_shared<Block>('Z',level);}
        else if (r==3) { b = make_shared<Block>('T',level);}
        else if (r==4) { b = make_shared<Block>('I',level);}
        else if (r==5) { b = make_shared<Block>('J',level);}
        else if (r==6) { b = make_shared<Block>('L',level);}
        else { b = make_shared<Block>('O',level); }
      } else {
        int r = rand() % 9 + 1;
        if ((r==1)||(r==2)) { b = make_shared<Block>('S',level); }
        else if ((r==3)||(r==4)) { b = make_shared<Block>('Z',level);}
        else if (r==5) { b = make_shared<Block>('T',level);}
        else if (r==6) { b = make_shared<Block>('I',level);}
        else if (r==7) { b = make_shared<Block>('J',level);}
        else if (r==8) { b = make_shared<Block>('L',level);}
        else { b = make_shared<Block>('O',level); }
      }
      return b;
}

bool dropBlock(int &curr_row, int &curr_col, shared_ptr<Block> &block, Board &board) {
  board.clearPiece(curr_row, curr_col, block);
  while (board.canPlace(curr_row, curr_col, block)) ++curr_row;
  --curr_row;
  board.setPiece(curr_row, curr_col, block);
  return board.clearRows();
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
  // Game variables
  int level = 0;
  int noClear = 0;
  bool blockMove = false;
  bool blockDrop = false;
  bool clearedRow = false;
  bool isHeavy = false;
  bool construct = false;
  int curr_row = 0, curr_col = 0;
  bool hintPlaced = false;
  shared_ptr<Block> hintBlock;
  Info hintInfo;
  // Initialization of the board
  Board gameBoard;


  string cmd;
  string block;
  bool newblock = 1;
  bool random = 1;
  int counter = 0;
  bool first=1;
  int done = 2;

//bool's for cmd line args
  bool seed = 0;
  bool startlevel = false; 

  string scriptfile = argv[argc-1];
  //Figuring out which cmd line args were entered
  for (int i = 1; i<argc-1; i++){
        string s = argv[i];
        if(s == "-text"){gameBoard.showGraphicsDisplay = false;
        } else if (s=="-seed"){ 
          istringstream iss(argv[i+1]);
          int seed;
          iss>>seed;
          srand(seed);
        }
        else if (s=="-scriptfile"){
        scriptfile = argv[i+1];
        } else if (s=="-startlevel"){
          istringstream iss(argv[i+1]);
          int n;
          iss>>n;
          if (n==1||n==2||n==3||n==4){ 
            level = n;
            gameBoard.setLevel(level);
          }
          if (n!=0){ startlevel = true;}
        }
  }
  gameBoard.init(level); // initalizing gamebaord
  if (level==3) isHeavy = true;
  if (level==4) {
      isHeavy = true;
       construct = true;
      }
  vector <string> cmds2;  
if (startlevel != true){
	ifstream f {scriptfile};
	string tt;
        cmds2.clear();
        while(f>>tt){
          cmds2.insert(cmds2.begin(), tt);
        }
}

  string s;     //name of initial file
  string s2;    //name of non random file
  if (startlevel != true){
  	s = cmds2.back();
  	cmds2.pop_back();
} else { s = "";}
  shared_ptr<Block> b = getblock(s, level, random);
  shared_ptr<Block> next;
      //cmds from norandom
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
        clearedRow = false;
        blockMove = false;
        blockDrop = false;
        string str;
        if ((level==0)||(random==0)){
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
        hintBlock = make_shared<Block>(b->getCell(0).type, level, true);
        hintInfo = gameBoard.hint(hintBlock);
        //If new block can be placed
        if (gameBoard.canPlace(curr_row, curr_col, b)) {
          gameBoard.setPiece(curr_row, curr_col, b);
          cout << gameBoard << endl;
          cout << "Next: " << endl;
          if (done>1) {
            printBlock(next->getCell(0).type);
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
      } else if (cmds3.size()!=0&&counter==0){
        cmd = cmds3.back();
        cmds3.pop_back();
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
      } else {
         counter --;
      }
      //Commands that don't need a block
      if (cmd=="restart"){
	gameBoard.init(level);
	string str;
        ifstream f {scriptfile};
        string tt;
        cmds2.clear();
        while(f>>tt){
          cmds2.insert(cmds2.begin(), tt);
        }
	if ((level==0)||(random==0)){
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
	b = getblock(str, level, random);
	// printing the block
          gameBoard.setPiece(curr_row, curr_col, b);
          cout << gameBoard << endl;
          cout << "Next: " << endl;
          if (done>1) {
            printBlock(next->getCell(0).type);
          } else { cout << endl << endl;}
      } else if (cmd == "levelup"){
        if (level!=4){
          level++;
          isHeavy = false;
          construct = false;
          if (level == 3) isHeavy = true;
          if (level == 4) {
            isHeavy = true;
            construct = true;
          }
        } else {
            cout << "You're on the highest level!" << endl;
        }
        gameBoard.setLevel(level);
      } else if (cmd == "leveldown"){
        if (level!=0){
          --level;
          isHeavy = false;
          construct = false;
          if (level == 3) isHeavy = true;
          if (level == 4) {
            isHeavy = true;
            construct = true;
          }
        } else {
            cout << "You're on the lowest level!" << endl;
        }
        gameBoard.setLevel(level);
      } else if (cmd == "norandom"){
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
        gameBoard.clearPiece(curr_row, curr_col, b);
        --curr_col;
        if (gameBoard.canPlace(curr_row, curr_col, b)) {
          gameBoard.setPiece(curr_row, curr_col, b);
        } else {
          ++curr_col;
          gameBoard.setPiece(curr_row, curr_col, b);
        }
        blockMove = true;
      } else if (cmd == "right"){
        gameBoard.clearPiece(curr_row, curr_col, b);
        ++curr_col;
        if (gameBoard.canPlace(curr_row, curr_col, b)) {
          gameBoard.setPiece(curr_row, curr_col, b);
        } else {
          --curr_col;
          gameBoard.setPiece(curr_row, curr_col, b);
        }
        blockMove = true;
      } else if (cmd == "down"){
        gameBoard.clearPiece(curr_row, curr_col, b);
        ++curr_row;
        if (gameBoard.canPlace(curr_row, curr_col, b)) {
          gameBoard.setPiece(curr_row, curr_col, b);
        } else {
          --curr_row;
          gameBoard.setPiece(curr_row, curr_col, b);
        }
        blockMove = true;
      } else if (cmd == "clockwise"){
        gameBoard.clearPiece(curr_row, curr_col, b);
        b->clockwise();
        if (gameBoard.canPlace(curr_row, curr_col, b)) {
          gameBoard.setPiece(curr_row, curr_col, b);
       } else {
          b->counter_clockwise();
          gameBoard.setPiece(curr_row, curr_col, b);
        }
        blockMove = true;
      } else if (cmd == "counterclockwise"){
        gameBoard.clearPiece(curr_row, curr_col, b);
        b->counter_clockwise();
        if (gameBoard.canPlace(curr_row, curr_col, b)) {
          gameBoard.setPiece(curr_row, curr_col, b);
        } else {
          b->clockwise();
          gameBoard.setPiece(curr_row, curr_col, b);
        }
        blockMove = true;
      } else if (cmd == "drop"){
        if(hintPlaced == true){
          gameBoard.clearPiece(hintInfo.row, hintInfo.col, hintBlock);
        }
        hintPlaced = false;
        clearedRow = dropBlock(curr_row, curr_col, b, gameBoard);
        newblock = 1;
        blockMove = true;
        blockDrop = true;
      } else if (cmd=="I"||cmd=="J"||cmd=="L"||cmd=="S"||cmd=="Z"||cmd=="T"||cmd=="O"){
                
      } else if (cmd=="hint"){
        hintPlaced = true;
        gameBoard.setPiece(hintInfo.row, hintInfo.col, hintBlock);
      }
      if (isHeavy && blockMove) {
        gameBoard.clearPiece(curr_row, curr_col, b);
        ++curr_row;
        if (gameBoard.canPlace(curr_row, curr_col, b)) {
          gameBoard.setPiece(curr_row, curr_col, b);
        } else {
          if(hintPlaced == true){
            gameBoard.clearPiece(hintInfo.row, hintInfo.col, hintBlock);
          }
          hintPlaced = false;
          --curr_row;
          clearedRow = dropBlock(curr_row, curr_col, b, gameBoard);
          newblock = 1;
          blockDrop = true;
        }
      }
      if (construct && blockDrop) {
        if (clearedRow) {
          noClear = 0;
        } else {
          if (noClear < 4) {
            ++noClear;
          } else {
            std::shared_ptr<Block> splitBlock;
            splitBlock = make_shared<Block>('*',level);
            gameBoard.placeSplit(splitBlock);
            noClear = 0;
          }
        }
      }

      if (newblock==0){
        cout << gameBoard << endl;
        cout << "Next: " << endl;
        printBlock(next->getCell(0).type);
      }
      if (done==0) break;
    }
  } catch (ios::failure &) {}  // Any I/O failure quits 
}
