#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Block{
	std::vector<std::vector<Cell>> theGrid;
	Observer<Info, State> *ob = nullptr;
	public:
	void rotate();
	void init(char b);
	bool canPlace();
	~Block();


}

