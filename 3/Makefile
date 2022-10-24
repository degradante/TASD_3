CC = gcc

CFLAGS = -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal

C_DIR = ./src
H_DIR = ./inc
O_DIR = ./out
HEADERS = alloc.h check_time.h init.h io.h

build: app.exe
app.exe: $(O_DIR)/main.o $(O_DIR)/io.o  $(O_DIR)/operations.o $(O_DIR)/alloc.o $(O_DIR)/check_time.o
	$(CC) $^ -o $@

$(O_DIR)/%.o: $(C_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
#-I$(H_DIR) $(HEADERS)

.PHONY: build clean
clean:
	rm -f $(O_DIR)/*.o *.exe