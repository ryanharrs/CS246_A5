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
  int level;
  int score;
  int hiscore;
  TextDisplay *td;
  private: 
  bool isEmpty(int row, int col);                                           // Checks if cell at given row and column is empty
  public:
  ~Board();
  void init(int currLevel);  
  void setLevel(int currLevel);
  void setPiece(int curr_row, int curr_col, std::shared_ptr<Block> &b);    
  bool canPlace(int curr_row, int curr_col, const std::shared_ptr<Block> &b);
  void clearPiece(int curr_row, int curr_col, const std::shared_ptr<Block> &b);
  void placeSplit(std::shared_ptr<Block> &b);
  bool clearRows();
  Info hint(std::shared_ptr<Block> &b);
  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
