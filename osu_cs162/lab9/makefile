# Sangyun Lee
# leesa6@oregonstate.edu
# makefile to create the executable file and clean it


CXX = g++
CXXFLAGS = -std=c++11
#CXXFLAGS += -wall
#CXXFLAGS += -pedantic-errors
LDFLAGS = -lboost_date_time

#OBJS = main.cpp 

SRCS = main.cpp queueTest.cpp stackString.cpp getInput.cpp
HEADERS = queueTest.hpp stackString.hpp getInput.hpp

lab1: ${SRCS} ${HEADER}
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o lab9

clean:
	rm lab9
