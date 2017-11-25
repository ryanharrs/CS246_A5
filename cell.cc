#include "cell.h"
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"
#include <iostream>
using namespace std;

Cell::Cell(size_t r, size_t c, char blockType): r{r}, c{c}, blockType{blockType}, colour{Colour::None}{}

Cell::Cell(size_t r, size_t c): r{r}, c{c}, colour{Colour::None}{}

void Cell::setPiece(Colour newColour){
	colour = newColour;
	State newState{StateType::NewPiece, colour, Direction::N};
	setState(newState);
	notifyObservers();	
}

//Finds direction of xy from ab
Direction directionFinder(int x, int y, int a, int b){ //xy-cords of new one, ab cords of old one
	if(x == a+1 && y == b){
		return Direction::S;
	}
	if(x == a+1 && y == b+1){
		return Direction::SE;
	}
	if(x == a+1 && y == b-1){
		return Direction::SW;
	}
	if(x == a && y == b-1){
		return Direction::W;
	}
	if(x == a && y == b+1){
		return Direction::E;
	}
	if(x == a-1 && y == b){
		return Direction::N;
	}
	if(x == a-1 && y == b-1){
		return Direction::NW;
	}
	if(x == a-1 && y == b+1){
		return Direction::NE;
	}
	return Direction::NE;

}

//finds the reverse of the curr direction (for reply function)
Direction reverseDirection(Direction curr){
	if(curr == Direction::S){
		return Direction::N;
	}
	if(curr == Direction::N){
		return Direction::S;
	}
	if(curr == Direction::E){
		return Direction::W;
	}
	if(curr == Direction::W){
		return Direction::E;
	}
	if(curr == Direction::NE){
		return Direction::SW;
	}
	if(curr == Direction::NW){
		return Direction::SE;
	}
	if(curr == Direction::SE){
		return Direction::NW;
	}
	if(curr == Direction::SW){
		return Direction::NE;
	}
	if(curr == Direction::S){
		return Direction::N;
	}
	return Direction::N;

}

void Cell::toggle(){
	if(colour == Colour::Black){
		colour = Colour::White;
	}
	else{
		colour = Colour::Black;
	}
}

void Cell::notify(Subject<Info, State> &whoFrom){
	
  	if(whoFrom.getState().type == StateType::NewPiece){
		if(colour != whoFrom.getState().colour && colour != Colour::None){
			State newState{StateType::Relay, colour, directionFinder(r,c,whoFrom.getInfo().row, whoFrom.getInfo().col)};
			setState(newState);
			notifyObservers();

		}

	}
  	else if(whoFrom.getState().type == StateType::Relay){
		Direction curr = directionFinder(r,c,whoFrom.getInfo().row, whoFrom.getInfo().col);
		if(curr == whoFrom.getState().direction){
			
			if(colour != whoFrom.getState().colour && colour != Colour::None){
				State newState{StateType::Reply, colour, reverseDirection(curr)};
				setState(newState);
				notifyObservers();
			}
	 		else if(colour == whoFrom.getState().colour){
				State newState{StateType::Relay, colour, curr};
				setState(newState);
				notifyObservers();
			}
	
		}
	}
  	else{
		Direction curr = directionFinder(r, c,whoFrom.getInfo().row, whoFrom.getInfo().col);
		if(colour != whoFrom.getState().colour && curr == whoFrom.getState().direction){
			State newState{StateType::Reply, whoFrom.getState().colour, curr};
			setState(newState);
			toggle();
			notifyObservers();
		} 

	}
}

Info Cell::getInfo()const{
	Info thisInfo{r,c,colour};
	return thisInfo;	
}

