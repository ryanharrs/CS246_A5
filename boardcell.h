#ifndef __BOARDCELL_H__
#define __BOARDCELL_H__
#include "block.h"
#include "subject.h"
#include "info.h"

class BoardCell : public Subject<Info> {
	int row;
	int col;
	char type;
	Block *bp;
	public:
	BoardCell(int row, int col, char type);
	Info getInfo();
	void setType(char getType);
	void setBP(Block *b);
	void delBP();
	~BoardCell();
};

#endif
