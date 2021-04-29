IDIC = ../include	
CC := g++	
CFLAGS := -Wall -Wextra -lstdc++fs -std=c++17
LDFLAGS := -lstdc++fs -std=c++17
SRC :=$(wildcard *.cpp)	
OBJ := $(SRC:.cpp=.o)	
OUT := antivirusTest	
$(OUT): $(OBJ)	
	$(CC) $^ -o $@ $(LDFLAGS)	
	
%.o: %.cpp	
	$(CC) $(CFLAGS) $< -c -o $@	
	
.PHONY: clean	
clean:
	rm -f $(OUT)	
	rm -f $(OBJ)
	
	
