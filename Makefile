CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = a4q5
OBJECTS = main.o window.o graphicsdisplay.o cell.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS}  -o ${EXEC} -lX11
 
-include ${DEPENDS}


clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

