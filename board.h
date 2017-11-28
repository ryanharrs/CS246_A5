#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "block.h"
#include "state.h"
#include "info.h"
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "graphicsdisplay.h"
class TextDisplay;
template <typename InfoType, typename StateType> class Observer;
class InvalidMove{};

class Board {
  std::vector<std::vector<Cell>> theBoard;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  Observer<Info, State> *ob = nullptr;  // Another observer (intent:  graphics)
  // Add private members, if necessary.
  GraphicsDisplay *gd = nullptr;
  bool checkIndividualRow(std::vector<Cell> row);
  void checkRows(Board &b, int level);
  int currScore = 0;
  public:
  int getCurrScore();
  ~Board();
  void init(); // Sets up an n x n grid.  Clears old grid, if necessary.
  bool isEmpty(Block &b);
  void newBlock(Block &b);
  void clearBlock(Block &b);
  void dropBlock(Block &b);
  void setPiece(size_t r, size_t c, BlockType type, Colour colour);  // Plays piece at row r, col c.

  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
