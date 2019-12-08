# Sangyun Lee
# leesa6@oregonstate.edu
# makefile to create the executable file and clean it


CXX = g++
CXXFLAGS = -std=c++11
#CXXFLAGS += -wall
#CXXFLAGS += -pedantic-errors
LDFLAGS = -lboost_date_time

#OBJS = main.cpp 

SRCS = main.cpp display.cpp output_letters.cpp count_letters.cpp
HEADERS = display.hpp output_letters.hpp count_letters.hpp

lab1: ${SRCS} ${HEADER}
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o lab2

clean:
	rm lab2
