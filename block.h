#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include "state.h"
#include "info.h"
#include "cell.h"

template <typename InfoType, typename StateType> class Observer;

class Block {
	std::vector<Cell> blockGrid;
 	public:
	void clockwiseRotate();
	void counterClockwiseRotate();
	void init(BlockType type);
	Info cellInfo(int idx);
	bool canPlace();
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	~Block();
};

#endif
