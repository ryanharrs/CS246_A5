#ifndef __BOARD_H__
#define __BOARD_H__
#include "block.h"
#include "boardcell.h"
#include "textdisplay.h"
#include "info.h"
#include "subject.h"
#include "observer.h"
#include <iostream>
#include <vector>
#include <cstddef>

class Board {
  std::vector<std::vector<BoardCell>> theBoard;
  int score;
  int hiscore;
  TextDisplay *td;
  private: 
  bool isEmpty(int row, int col);                                           // Checks if cell at given row and column is empty
  public:
  bool showGraphicsDisplay = false;
  ~Board();
  void init(); 
  Info hint(Block &b);
  void setPiece(int curr_row, int curr_col, Block &b);    
  bool canPlace(int curr_row, int curr_col, const Block &b);
  void clearPiece(int curr_row, int curr_col, const Block &b);
  void clearRows(int currLevel);
  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
