#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"

class Cell : public Subject<Info, State>, public Observer<Info,State>{
  const size_t r, c;
  BlockType type = BlockType::None;
  Colour colour = Colour::None;
  int sameBlockCells = 0;
  // Add other private members if necessary

 public:
  int sameBlockCells();
  Cell(size_t r, size_t c, BlockType type);
  Cell(size_t r, size_t c);
  void setPiece(BlockType getType, Colour getColour);    // Place a piece of given colour here.
  ~Cell();
  Info getInfo() const override;
 	void notify(Subject<Info, State> &whoFrom) override; 
};
#endif

