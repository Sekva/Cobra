LIBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CXX = g++

SRC_DIR = ./src/
OBJETOS_DIR = ./objetos/
BUILD_DIR = ./build/

SRCS = main.cpp \
comida.cpp \
cobra.cpp \
parte.cpp

BIN_NOME = jojo

OBJS = $(SRCS:.cpp=.o)

OBJS_FINAL = $(OBJS:%.o=$(OBJETOS_DIR)%.o)

BIN = $(BUILD_DIR)$(BIN_NOME)

all : $(BIN)

$(BIN) : $(OBJS_FINAL)
	$(CXX) $(OBJS_FINAL) -o $(BIN) $(LIBFLAGS)

$(OBJS_FINAL) : $(OBJETOS_DIR)%.o : $(SRC_DIR)%.cpp
	$(CXX) -c $< -o $@

clean :
	rm  $(BIN) $(OBJS_FINAL)
