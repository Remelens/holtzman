CPL=g++
FLAG=-O2 --std=c++17 -Wall -static-libgcc

LIBCPPHTTPLIB_SUPPORT=-lcpp-httplib
server:server.cpp error.hpp
	$(CPL) server.cpp -o server $(LIBCPPHTTPLIB_SUPPORT) $(FLAG)
