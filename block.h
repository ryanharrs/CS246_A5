#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <string>
#include <iostream>
#include "subject.h"
#include "observer.h"
#include "state.h"
#include "cell.h"
#include "info.h"
template <typename InfoType, typename StateType> class Observer;

class Block: public Subject<Info, State>{
	
 	public:
	int x,y,width,height;
	std::string blockType;
	std::vector<std::vector<Cell>> blockGrid;
	void clockwiseRotate();
	void counterClockwiseRotate();
	void init(std::string bt);
	bool canPlace();
	~Block();
	Info getInfo() const override;

};

#endif