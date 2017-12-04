CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = a5
OBJECTS = main.o board.o block.o textdisplay.o window.o boardcell.o graphicsdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS}  -o ${EXEC} -lX11
 
-include ${DEPENDS}


clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

