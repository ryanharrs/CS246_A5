#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Block{
	std::vector<std::vector<Cell>> *blockGrid;
	Observer<Info, State> *ob = nullptr;
	public:
	void clockwiseRotate();
	void counterClockwiseRotate();
	void init(char blockType);
	bool canPlace();
	~Block();


}

