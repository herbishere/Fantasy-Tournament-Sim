
CXX = g++
CXXFLAGS = -Wall
CXXFLAGS = -pedantic_errors
CXXFLAGS = -g
CXXFLAGS = --std=c++11

SRCS = main.cpp Die.cpp Character.cpp Barbarian.cpp BlueMen.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp menuFunctions.cpp Lineup.cpp Tournament.cpp

HEADERS = Die.hpp Character.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp menuFunctions.hpp FighterNode.hpp Lineup.hpp Tournament.hpp

MISC = p04Reflection.pdf

main: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} $(CXXFLAGS) -o main

clean:
	rm -f main

zip:
	zip -D Project04_Diaz_Herbert ${SRCS} ${HEADERS} ${MISC} makefile
