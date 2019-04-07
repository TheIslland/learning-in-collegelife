CXX := g++
CFLAGS := -std=c++11 -g #-wall
OBJS = *.cpp *.c
LIBA = ../thirdpart/libs/libantlr3c.a

test: 
	@java -jar ../antlr-3.4-complete.jar ./hl.g
	@$(CXX) $(CFLAGS) $(OBJS) $(LIBA) -o test -I. -I ../thirdpart/include/

.PHONY: clean install
clean:
	@rm test

install:
	@cp ../libantlr3c-3.4/include/* ./include
	@cp ../libantlr3c-3.4/.libs/libantlr3c.a ./libs
