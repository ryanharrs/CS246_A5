#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
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
  std::vector<std::vector<Block>> theBoard;  // The actual grid.
  TextDisplay *td = nullptr; // The text display.
  Observer<Info, State> *ob = nullptr;  // Another observer (intent:  graphics)
  // Add private members, if necessary.
  GraphicsDisplay *gd = nullptr;
  public:
  ~Board();
  
  void setObserver(Observer<Info, State> *setob);
  bool isFull() const;  // Is the game over, i.e., is the grid full?
  Colour whoWon() const; // Who has more pieces when the board is full?
  void init(size_t n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void setPiece(size_t r, size_t c, Colour colour);  // Plays piece at row r, col c.
  void toggle(size_t r, size_t c);  // Flips piece at row r, col c.

  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
