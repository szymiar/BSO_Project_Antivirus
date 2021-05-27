IDIC := ../include
ODIR := obj
CC := g++	
CFLAGS := -Wall -Wextra -lstdc++fs -pthread -std=c++17
LDFLAGS := -lssl -lcrypto -lstdc++fs -pthread -std=c++17
SRC :=$(wildcard *.cpp)	
_OBJ := $(SRC:.cpp=.o)
OBJ := $(patsubst %, $(ODIR)/%,$(_OBJ))	
OUT := ../antivirusBSO	
$(OUT): $(OBJ)	
	$(CC) $^ -o $@ $(LDFLAGS)	
	
$(ODIR)/%.o: %.cpp	
	$(CC) $(CFLAGS) $< -c -o $@	
	
.PHONY: clean	
clean:
	rm -f $(OUT)	
	rm -f $(OBJ)
	
	
