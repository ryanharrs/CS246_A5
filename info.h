#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "block.h"
#include <memory>

struct Info {
  int row, col;
  char type;
  std::shared_ptr<Block> bp;
};

#endif
