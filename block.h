#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include "blockcell.h"

class Block {
	std::vector<BlockCell> blockGrid;
	int position;
	int level;
	int pieces;
	bool isHint;
	char blockType;
 	public:
	Block(char type, int currLevel);
	Block(char type, int currLevel, bool isHintVar);
	BlockCell getCell(int idx) const;
	void clockwise();
	void counter_clockwise();
	int getLevel();
	int numPieces() const;
	void decPieces();
	char getType();
	bool getIfHint();
	~Block();
};

#endif
