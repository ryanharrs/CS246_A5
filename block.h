#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include "state.h"
#include "info.h"
#include "cell.h"
#include "graphicsdisplay.h"
template <typename InfoType, typename StateType> class Observer;

class Block {
	std::vector<Cell> blockGrid;
	Cell *middle = nullptr;
	void updateBlockRows();
	int blockLevel;
	bool findNum(std::vector<int> row, int j);
	int rotationVersion = 0;
 	public:
	int getBlockLevel();
	std::vector<int> blockRows;
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
