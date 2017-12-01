#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include "blockcell.h"

class Block {
	std::vector<BlockCell> blockGrid;
	int position;
	int level;
	int pieces;
 	public:
	Block(char type, int currLevel);
	BlockCell getCell(int idx) const;
	void clockwise();
	void counter_clockwise();
	int getLevel();
	int numPieces();
	void decPieces();
	~Block();
};

#endif
