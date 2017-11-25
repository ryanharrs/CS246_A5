#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

template <typename InfoType, typename StateType> class Observer;

class Block: public Subject<Info, State>{
	
 	public:
	std::vector<std::vector<Cell>> *blockGrid;
	int x,y, height, width;
	void clockwiseRotate();
	void counterClockwiseRotate();
	void init(string blockType);
	bool canPlace();
	~Block();
};

