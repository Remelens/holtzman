CPL=g++
FLAG=-O2 --std=c++17 -Wall -static-libgcc

ifeq ($(OS),Windows_NT)
	LIB_SUPPORT=-lws2_32
else
	LIB_SUPPORT=
endif

server:server.cpp error.hpp
	$(CPL) server.cpp -o server $(LIB_SUPPORT) $(FLAG)
