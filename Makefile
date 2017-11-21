CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = a4q5
OBJECTS = main.o window.o graphicsdisplay.o textdisplay.o subject.o observer.o info.o grid.o cell.o state.o observer.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS}  -o ${EXEC} -lX11
 
-include ${DEPENDS}


clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

