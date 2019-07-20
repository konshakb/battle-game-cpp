

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
LDFLAGS = -lboost_date_time

OBJS = main

SRCS = main.cpp battle.cpp Creature.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Die.cpp Stack.cpp Queue.cpp

HEADERS = Creature.hpp battle.hpp Vampire.hpp Barbarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp Die.hpp Stack.hpp Queue.hpp


#target:  dependencies
#	rule to build
#	




main:  $(SRCS) $(HEADERS)
	${CXX} ${CXXFLAGS} main.cpp battle.cpp Stack.cpp Queue.cpp Creature.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Die.cpp -o main

clean: 
	rm ${OBJS}
