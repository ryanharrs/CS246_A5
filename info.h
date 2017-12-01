#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "block.h"

struct Info {
  int row, col;
  char type;
  Block *bp;
};

#endif
