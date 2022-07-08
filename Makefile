INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
EXE = particles

CC = gcc
OPTIMIZATION = -O3
CFLAGS = -Wall -Wextra -I $(INC_DIR) -c -std=c17 $(OPTIMIZATION)
LINK_LINUX = -L $(LIB_DIR) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 # Works also without last two
LINK_WINDOWS = -L $(LIB_DIR) -lraylib -lopengl32 -lgdi32 -lwinmm
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/particle.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/particle.o

windows: $(OBJ_DIR)_windows $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(OPTIMIZATION) $(LINK_WINDOWS)

linux: $(OBJ_DIR)_linux $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(OPTIMIZATION) $(LINK_LINUX)

$(OBJ_DIR)_linux:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)_windows:
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

run_linux: linux
	./$(EXE)

run_windows: windows
	.\$(EXE)