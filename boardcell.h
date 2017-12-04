#ifndef __BOARDCELL_H__
#define __BOARDCELL_H__
#include "block.h"
#include "subject.h"
#include "info.h"
#include <memory>

class BoardCell : public Subject<Info> {
	int row;
	int col;
	char type;
	std::shared_ptr<Block> bp;
	public:
	BoardCell(int row, int col, char type);
	Info getInfo();
	void setType(char getType);
	void setSP(std::shared_ptr<Block> &b);
	void clearSP();
	~BoardCell();
};

#endif
