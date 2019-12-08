# Sangyun Lee
# leesa6@oregonstate.edu
# makefile to create the executable file and clean it


CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -wall
#CXXFLAGS += -pedantic-errors
LDFLAGS = -lboost_date_time

#OBJS = main.cpp 

SRCS = main.cpp readMatrix.cpp determinant.cpp
HEADERS = readMatrix.hpp determinant.hpp

lab1: ${SRCS} ${HEADER}
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o lab1

clean:
	rm lab1
