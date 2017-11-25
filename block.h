#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

template <typename InfoType, typename StateType> class Observer;

class Block{
	std::vector<std::vector<Cell>> *blockGrid;
 	std::vector<Observer<InfoType, StateType>*> observers;
	public:
	void attach(Observer<InfoType, StateType> *o);
	void notifyObservers();
	void clockwiseRotate();
	void counterClockwiseRotate();
	void init(string blockType);
	bool canPlace();
	~Block();


}

